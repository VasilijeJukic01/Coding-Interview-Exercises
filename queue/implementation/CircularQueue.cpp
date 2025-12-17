/*
* Circular Queue Implementation (Fixed Capacity).
 * 
 * Logic: (index + 1) % capacity allows the pointers to wrap around to 0.
 * 
 * Pros: Space efficient, reuses empty slots.
 * Cons: Fixed capacity.
 */

#include <iostream>
#include <vector>

using namespace std;

class CircularQueue {
private:
    vector<int> data;
    int head, tail, capacity, count;

public:
    CircularQueue(int k) : data(k), capacity(k), head(0), tail(-1), count(0) {}

    bool enqueue(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % capacity;
        data[tail] = value;
        count++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

int main() {
    CircularQueue cq(3);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.dequeue();
    cq.enqueue(4); // Wraps around to fill index 0
    
    cout << "Front: " << cq.Front() << " | Rear: " << cq.Rear() << endl; // 2, 4
    
    return 0;
}