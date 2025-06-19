/*
The Distributed Log Aggregator

You are designing a core component for a large-scale distributed database. The system consists of many nodes that 
replicate data for fault tolerance and high availability. Every write operation (like CREATE, UPDATE, DELETE) is 
first recorded as a log entry before being applied to the database. These log entries are timestamped to ensure a 
consistent ordering of operations across the entire system.
Each node in the cluster maintains its own copy of this distributed log. When a node receives an operation, it 
broadcasts the log entry (timestamp + operation data) to all other nodes. Due to network latency, these log entries 
can arrive out of order at different nodes. However, each node must store them in a structure that is strictly sorted 
by timestamp.

This sorted log is crucial for several tasks:
- State Reconciliation: A node that was offline can "catch up" by querying the log from a specific point in time.
- Auditing: Administrators need to efficiently query for all operations that occurred within a specific time window.
- High Throughput: The system must handle a massive influx of concurrent log entries from other nodes.

Your task is to design and implement a data structure on a single node for storing these log entries. This structure 
must satisfy the following requirements:
1) Efficient Insertion: It must be able to insert new log entries, which may arrive out of order, into their correct 
sorted position quickly.
2) Efficient Range Queries: It must support fast lookups for all log entries within a given [startTimestamp, endTimestamp] 
window.
3) High Concurrency: The data structure must be designed to perform well under heavy, concurrent insertions. 
This is the most critical aspect of a distributed system. A solution that requires locking the entire structure for 
every insert will create a bottleneck and fail.

You need to implement a class LogAggregator that supports two main operations:

1) RECORD(timestamp, operation_data)
Description: Inserts a new log entry into the data structure. timestamp is a unique long representing time, 
and operation_data is a string describing the operation (e.g., "UPDATE users SET status='active' WHERE id=123").
Complexity Goal: Expected O(log N), where N is the number of entries in the log.

2) QUERY(startTimestamp, endTimestamp)
Description: Returns a list of all operation_data strings for log entries whose timestamps fall within the inclusive 
range [startTimestamp, endTimestamp], sorted by timestamp.
Complexity Goal: Expected O(log N + K), where N is the number of entries in the log and K is the number of entries in 
the result set.

Constraints:
1 <= timestamp <= 10^18
The total number of log entries N can be up to 10^7.
The number of concurrent RECORD operations is very high.
The operation_data is a string of variable length.
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <mutex>
#include <shared_mutex>
#include <random>

#define MAX_LEVEL 16

using namespace std;

// Log Entry
class LogEntry {
public:
    long long timestamp;
    string operationData;
    LogEntry **forward;
    mutable shared_mutex lock;

    LogEntry(long long, string, int);
    ~LogEntry();
};

LogEntry::LogEntry(long long timestamp, string operationData, int level) {
    this->timestamp = timestamp;
    this->operationData = operationData;

    this->forward = new LogEntry*[level + 1];
    memset(forward, 0, sizeof(LogEntry*) * (level + 1));
};

LogEntry::~LogEntry() {
    delete[] forward;
}

// Log Aggregator
class LogAggregator {
    float probability;
    int level;
    LogEntry* header;

    // For Randomization
    mt19937 gen;
    uniform_real_distribution<> dis;

public:
    LogAggregator(float);
    void record(long long, string);
    vector<string> query(long long, long long);
    void displayLogs();

    ~LogAggregator() {
        LogEntry* current = header->forward[0];
        while (current) {
            LogEntry* next = current->forward[0];
            delete current;
            current = next;
        }
        delete header;
    };

private:
    int randomLevel();
    LogEntry* createEntry(long long, string, int);
};

LogAggregator::LogAggregator(float probability) : gen(random_device{}()), dis(0.0, 1.0) {
    this->probability = probability;
    this->level = 0;
    this->header = new LogEntry(0l, "", MAX_LEVEL);
};

// Private
int LogAggregator::randomLevel() {
    int lvl = 0;
    while (dis(gen) < probability && lvl < MAX_LEVEL) {
        lvl++;
    }
    return lvl;
}

LogEntry* LogAggregator::createEntry(long long timestamp, string operationData, int level) {
    LogEntry* log = new LogEntry(timestamp, operationData, level);
    return log;
};

// Public
void LogAggregator::displayLogs() {
    cout << endl;
    for (int i = level; i >= 0; i--) {
        cout << "Level " << i << ": ";

        LogEntry* levelPtr = header->forward[i];
        LogEntry* basePtr = header->forward[0];

        while (basePtr) {
            if (levelPtr && levelPtr->timestamp == basePtr->timestamp) {
                cout << setw(4) << levelPtr->timestamp << " ";
                levelPtr = levelPtr->forward[i];
            } else {
                cout << "---- ";
            }
            basePtr = basePtr->forward[0];
        }
        cout << endl;
    }
};

void LogAggregator::record(long long timestamp, string operationData) {
    LogEntry* update[MAX_LEVEL + 1];

    while (true) {
        // Find Predecessors
        LogEntry* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->timestamp < timestamp) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        LogEntry* successor = update[0]->forward[0];

        // Lock Predecessors
        set<LogEntry*> entriesToLockSet;
        for (int i = 0; i <= level; ++i) {
            entriesToLockSet.insert(update[i]);
        }
        vector<LogEntry*> entriesToLock(entriesToLockSet.begin(), entriesToLockSet.end());

        // Deadlock prevention
        sort(entriesToLock.begin(), entriesToLock.end());

        vector<unique_lock<shared_mutex>> locks;
        for (auto* entry : entriesToLock) {
            locks.emplace_back(entry->lock);
        }

        if (update[0]->forward[0] != successor) {
            // Path changed -> retry the whole operation
            // Locks release automatically
            continue;
        }

        if (successor && successor->timestamp == timestamp) return;

        // Record
        int entryLevel = randomLevel();

        if (entryLevel > level) {
            for (int i = level + 1; i <= entryLevel; i++) {
                update[i] = header;
            }
            level = entryLevel;
        }

        LogEntry* log = createEntry(timestamp, operationData, entryLevel);

        for (int i = 0; i <= entryLevel; i++) {
            log->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = log;
        }

        break;
    }
}

vector<string> LogAggregator::query(long long startTimestamp, long long endTimestamp) {
    vector<string> result;

    LogEntry* pred = header;

    // Reader-Writer Lock
    shared_lock<shared_mutex> predLock(pred->lock);

    for (int i = level; i >= 0; i--) {
        LogEntry* next = pred->forward[i];
        while (next && next->timestamp < startTimestamp) {
            next = pred->forward[i];

            if (!next || next->timestamp >= startTimestamp)
                break;

            shared_lock<shared_mutex> nextLock(next->lock);
            predLock.unlock();
            pred = next;
            predLock = move(nextLock);
        }
    }

    LogEntry* current = pred->forward[0];

    while (current && current->timestamp <= endTimestamp) {
        // Writer cannot change its data
        shared_lock<shared_mutex> currentLock(current->lock);

        result.push_back(current->operationData);
        LogEntry* next = current->forward[0];

        predLock.unlock();

        current = next;

        // Transfer the lock
        predLock = move(currentLock);
    }

    return result;
};

int main() {
    LogAggregator aggregator(0.5);

    aggregator.record(100, "UPDATE users SET name = 'Alice' WHERE id = 1");
    aggregator.record(50, "UPDATE users SET email = 'bob@example.com' WHERE id = 2");
    aggregator.record(150, "INSERT INTO orders (user_id, total) VALUES (1, 99.99)");
    aggregator.record(75, "DELETE FROM sessions WHERE expires_at < NOW()");
    aggregator.record(120, "SELECT * FROM users WHERE active = 1");
    aggregator.record(200, "UPDATE users SET last_login = NOW() WHERE id = 3");

    cout << "Querying logs between 70 and 160:" << endl;
    vector<string> result = aggregator.query(70, 160);
    for (string op : result) {
        cout << "- " << op << endl;
    }

    return 0;
}
