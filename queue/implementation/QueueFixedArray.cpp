/*
 * Queue Implementation using a Fixed-Size Array.
 * 
 * Pros: Very fast, O(1) operations.
 * Cons: False Overflow - Once tail hits capacity, you can't insert even if front elements were popped.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class QueueFixed {
private:
    T* arr;
    int capacity;
    int head;
    int tail;

public:
    QueueFixed(int size = 100) {
        capacity = size;
        arr = new T[capacity];
        head = 0;
        tail = 0;
    }

    ~QueueFixed() { delete[] arr; }

    void enqueue(T value) {
        if (tail == capacity) {
            throw overflow_error("Queue Overflow.");
        }
        arr[tail++] = value;
    }

    void dequeue() {
        if (isEmpty()) throw underflow_error("Queue Underflow.");
        head++;
    }

    T front() {
        if (isEmpty()) throw underflow_error("Queue is empty.");
        return arr[head];
    }

    bool isEmpty() {
        return head == tail;
    }
    
    int size() {
        return tail - head;
    }
};

int main() {
    QueueFixed<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    
    cout << "Front: " << q.front() << endl; // 20
    
    return 0;
}