/*
 * Hash Map using Open Addressing (Linear Probing)
 *
 * Concepts:
 * - Single array stores data.
 * - If collision occurs, linearly probe (index + 1) until empty slot found.
 * - Deletion requires "Tombstone" (Lazy Deletion) to preserve probe chains.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum EntryState { EMPTY, OCCUPIED, DELETED };

template <typename K, typename V>

struct HashEntry {
    K key;
    V value;
    EntryState state;

    HashEntry() : state(EMPTY) {}
};

template <typename K, typename V>

class HashMapLinear {
private:
    vector<HashEntry<K, V>> table;
    int capacity;
    int size;
    const double LOAD_FACTOR_THRESHOLD = 0.5;

    int hashFunction(K key) {
        hash<K> hasher;
        return hasher(key) % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        vector<HashEntry<K, V>> oldTable = table;

        capacity *= 2;
        table.clear();
        table.resize(capacity);
        size = 0;

        for (int i = 0; i < oldCapacity; i++) {
            if (oldTable[i].state == OCCUPIED) {
                put(oldTable[i].key, oldTable[i].value);
            }
        }
    }

public:
    HashMapLinear(int cap = 16) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    void put(K key, V value) {
        if ((double) size / capacity > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }

        int hash = hashFunction(key);
        int index = hash;
        int firstDeleted = -1;

        while (table[index].state != EMPTY) {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                // Update
                table[index].value = value;
                return;
            }
            if (table[index].state == DELETED && firstDeleted == -1) {
                // Remember first tombstone to optimize insertion
                firstDeleted = index;
            }
            index = (index + 1) % capacity;
            // Table full (should be handled by resize)
            if (index == hash) return;
        }

        // Insert at first deleted slot if available, else at the empty slot found
        if (firstDeleted != -1) index = firstDeleted;

        table[index].key = key;
        table[index].value = value;
        table[index].state = OCCUPIED;
        size++;
    }

    bool get(K key, V& outValue) {
        int hash = hashFunction(key);
        int index = hash;

        while (table[index].state != EMPTY) {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                outValue = table[index].value;
                return true;
            }
            index = (index + 1) % capacity;
            if (index == hash) return false;
        }
        return false;
    }

    void remove(K key) {
        int hash = hashFunction(key);
        int index = hash;

        while (table[index].state != EMPTY) {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                // Mark as tombstone
                table[index].state = DELETED;
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == hash) return;
        }
    }

    int getSize() { return size; }
};

int main() {
    HashMapLinear<string, int> map;
    map.put("One", 1);
    map.put("Two", 2);
    map.put("Three", 3);

    int val;
    if (map.get("Two", val)) cout << "Two: " << val << endl;

    map.remove("Two");

    if (!map.get("Two", val)) cout << "Two removed." << endl;

    // Test that probe chain isn't broken
    if (map.get("Three", val)) cout << "Three still accessible: " << val << endl;

    return 0;
}