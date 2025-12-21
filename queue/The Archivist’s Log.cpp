/*
In the Great Library of Alexandria, a lead archivist is responsible for tracking how many scholars request access to 
the Forbidden Scrolls. To ensure the scrolls aren't handled too often, the archivist must keep a strict count of 
all requests that occurred within the last 5,000 minutes. Every time a scholar arrives at time t (in minutes), the 
archivist notes it down and must immediately report how many scholars (including the current one) have touched the 
scrolls within the range [t - 5000, t]

Implement a tracker that receives timestamps in strictly increasing order and returns the count of requests in the 
last 5,000 minutes.

Input:
Record(100), Record(2000), Record(5100), Record(6000), Record(11000)

Output:
Record(100) -> 1 (Log: [100])
Record(2000) -> 2 (Log: [100, 2000])
Record(5100) -> 3 (Log: [100, 2000, 5100])
Record(6000) -> 3 (Log: [2000, 5100, 6000]. 100 is too old: 6000-5000=1000)
Record(11000) -> 1 (Log: [11000]. All previous are too old)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solve(const vector<int>& timestamps, int window) {
    vector<int> results;
    queue<int> q;

    for (int t : timestamps) {
        q.push(t);
        while (!q.empty() && q.front() < t - window) {
            q.pop();
        }
        results.push_back(q.size());
    }
    return results;
}

int main() {
    vector<int> timestamps = {100, 2000, 5100, 6000, 11000};
    vector<int> results = solve(timestamps, 5000);

    for (int count : results) {
        cout << count << " ";
    }

    return 0;
}