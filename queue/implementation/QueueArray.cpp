/*
* Dynamic Circular Queue.
 * 
 * Mechanism: When full, creates a new array double the size and unrolls the circular elements into the new array.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class QueueDynamic {
private:
    T* arr;
    int head, tail, count, capacity;

    void resize() {
        int newCap = capacity * 2;
        T* newArr = new T[newCap];
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(head + i) % capacity];
        }
        delete[] arr;
        arr = newArr;
        head = 0;
        tail = count - 1;
        capacity = newCap;
    }

public:
    QueueDynamic(int initCap = 2) : capacity(initCap), head(0), tail(-1), count(0) {
        arr = new T[capacity];
    }

    void enqueue(T val) {
        if (count == capacity) resize();
        tail = (tail + 1) % capacity;
        arr[tail] = val;
        count++;
    }

    void dequeue() {
        if (count == 0) return;
        head = (head + 1) % capacity;
        count--;
    }

    T front() {
        return arr[head];
    }
    
    int size() {
        return count;
    }
};

int main() {
    QueueDynamic<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3); // Triggers resize
    
    cout << "Size after resize: " << q.size() << " | Front: " << q.front() << endl;
    
    return 0;
}