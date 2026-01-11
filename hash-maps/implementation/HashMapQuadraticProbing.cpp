/*
 * Hash Map using Open Addressing (Quadratic Probing)
 *
 * Concepts:
 * - Avoids "Primary Clustering" of Linear Probing.
 * - Probe sequence: hash, hash + 1^2, hash + 2^2, ...
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

class HashMapQuadratic {
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

        capacity *= 2; // Should ideally be a prime number for quadratic probing
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
    // Prime start usually better
    HashMapQuadratic(int cap = 17) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    void put(K key, V value) {
        if ((double) size / capacity > LOAD_FACTOR_THRESHOLD) rehash();

        int hash = hashFunction(key);
        int i = 0;
        int index = hash;

        while (table[index].state != EMPTY) {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                table[index].value = value;
                return;
            }
            i++;
            index = (hash + i * i) % capacity; // Quadratic probe
            // Safety break, though rehash prevents this
            if (i > capacity) {
                rehash();
                put(key, value);
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].state = OCCUPIED;
        size++;
    }

    bool get(K key, V& outValue) {
        int hash = hashFunction(key);
        int i = 0;
        int index = hash;

        while (table[index].state != EMPTY || table[index].state == DELETED) {
            if (table[index].state == OCCUPIED && table[index].key == key) {
                outValue = table[index].value;
                return true;
            }
            if (table[index].state == EMPTY) return false;

            i++;
            index = (hash + i * i) % capacity;
            if (i > capacity) return false;
        }
        return false;
    }
};

int main() {
    HashMapQuadratic<int, string> map;
    map.put(1, "Data 1");
    map.put(18, "Data 18"); // If cap=17, 18%17 = 1 (Collision)

    string val;
    if (map.get(1, val)) cout << val << endl;
    if (map.get(18, val)) cout << val << endl; // Should find via quadratic probe

    return 0;
}