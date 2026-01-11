/*
 * Hash Map using Separate Chaining
 *
 * Concepts:
 * - Array of buckets (linked lists).
 * - Collisions handled by appending to the list at the hashed index.
 * - Dynamic resizing (Rehashing) when Load Factor > threshold.
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename K, typename V>

class HashMap {
private:
    struct HashNode {
        K key;
        V value;
        HashNode(K k, V v) : key(k), value(v) {}
    };

    vector<list<HashNode>> buckets;
    int capacity;
    int size;
    const double LOAD_FACTOR_THRESHOLD = 0.75;

    int hashFunction(K key) {
        hash<K> hasher;
        return hasher(key) % capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        vector<list<HashNode>> oldBuckets = buckets;

        buckets.clear();
        buckets.resize(capacity);
        size = 0;

        for (int i = 0; i < oldCapacity; i++) {
            for (auto& node : oldBuckets[i]) {
                put(node.key, node.value);
            }
        }
    }

public:
    HashMap(int cap = 10) : capacity(cap), size(0) {
        buckets.resize(capacity);
    }

    void put(K key, V value) {
        int index = hashFunction(key);

        // Update if exists
        for (auto& node : buckets[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }

        // Insert new key
        buckets[index].emplace_back(key, value);
        size++;

        if ((double) size / capacity > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }
    }

    bool get(K key, V& outValue) {
        int index = hashFunction(key);
        for (auto& node : buckets[index]) {
            if (node.key == key) {
                outValue = node.value;
                return true;
            }
        }
        return false;
    }

    void remove(K key) {
        int index = hashFunction(key);
        auto& chain = buckets[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->key == key) {
                chain.erase(it);
                size--;
                return;
            }
        }
    }

    bool contains(K key) {
        V temp;
        return get(key, temp);
    }

    int getSize() {
        return size;
    }
};

int main() {
    HashMap<string, int> map;
    map.put("Alice", 25);
    map.put("Bob", 30);
    map.put("Charlie", 35);
    map.put("Alice", 26); // Update

    int age;
    if (map.get("Alice", age)) cout << "Alice's age: " << age << endl; // 26

    map.remove("Bob");
    if (!map.get("Bob", age)) cout << "Bob not found." << endl;

    return 0;
}