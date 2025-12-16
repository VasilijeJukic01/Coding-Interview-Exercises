/*
 * Stack Implementation using a Fixed-Size Raw Array.
 * 
 * Pros:
 * - Fast and cache-friendly (contiguous memory).
 * - No overhead for pointers.
 * 
 * Cons:
 * - Fixed size: Capacity must be defined at creation.
 * - Stack Overflow: Can fill up if capacity is reached.
 */

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>

class StackFixed {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    StackFixed(int size = 100) {
        if (size <= 0) throw invalid_argument("Size must be positive");
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~StackFixed() {
        delete[] arr;
    }

    void push(T value) {
        if (topIndex >= capacity - 1) {
            throw overflow_error("Stack Overflow.");
        }
        arr[++topIndex] = value;
    }
    
    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow.");
        }
        topIndex--;
    }
    
    T top() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty.");
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
    
    bool isFull() {
        return topIndex == capacity - 1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    try {
        // Create a small stack of size 3 to test overflow
        StackFixed<string> s(3);

        s.push("Apple");
        s.push("Banana");
        s.push("Cherry");
        
        cout << "Top: " << s.top() << endl;
        
        // s.push("Date"); // This will throw Stack Overflow

        s.pop();
        cout << "Top after pop: " << s.top() << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}