/*
 * Circular Double-Ended Queue using a Fixed-Size Array.
 *
 * Logic:
 * - Insert Front: Move head counter-clockwise -> (head - 1 + capacity) % capacity
 * - Insert Rear:  Move tail clockwise         -> (tail + 1) % capacity
 * - Delete Front: Move head clockwise         -> (head + 1) % capacity
 * - Delete Rear:  Move tail counter-clockwise -> (tail - 1 + capacity) % capacity
 *
 * Complexity: All operations are O(1).
 */

#include <iostream>
#include <vector>

using namespace std;

class CircularDeque {
private:
    vector<int> arr;
    int head;
    int tail;
    int capacity;
    int currentSize;

public:
    CircularDeque(int k) : arr(k), capacity(k), head(0), tail(0), currentSize(0) {
        // Initialize tail at 0, but technically insertion at rear will happen at index tail, then tail moves.
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        // Move head backward
        head = (head - 1 + capacity) % capacity;
        arr[head] = value;
        currentSize++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        // Insert at current tail, then move tail forward
        arr[tail] = value;
        tail = (tail + 1) % capacity;
        currentSize++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        // Move head forward
        head = (head + 1) % capacity;
        currentSize--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        // Move tail backward
        tail = (tail - 1 + capacity) % capacity;
        currentSize--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[head];
    }

    int getRear() {
        // Rear is always (tail - 1) because tail points to the next empty slot
        return isEmpty() ? -1 : arr[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }
};

int main() {
    CircularDeque dq(3);

    cout << boolalpha;
    cout << "Insert Last 1: " << dq.insertLast(1) << endl;   // [1]
    cout << "Insert Last 2: " << dq.insertLast(2) << endl;   // [1, 2]
    cout << "Insert Front 3: " << dq.insertFront(3) << endl; // [3, 1, 2]
    cout << "Insert Front 4: " << dq.insertFront(4) << endl; // false (Full)

    cout << "Rear: " << dq.getRear() << endl;   // 2
    cout << "Front: " << dq.getFront() << endl; // 3

    dq.deleteLast();  // [3, 1]
    cout << "New Rear after delete: " << dq.getRear() << endl; // 1

    return 0;
}