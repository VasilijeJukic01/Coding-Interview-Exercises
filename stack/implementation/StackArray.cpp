/*
 * Stack Implementation using a Dynamic Array (std::vector).
 *
 * Underlying Mechanism:
 * We use std::vector, which manages a dynamic array internally. 
 * When the capacity is full, the vector allocates a new, larger block of memory, copies elements, and deletes the old block.
 *
 * Complexity Analysis:
 * - Push: Average O(1). Worst case O(N) when resizing occurs. 
 *   However, because resizing happens rarely (exponential growth), the Amortized complexity is O(1).
 * - Pop: O(1).
 * - Top: O(1).
 * 
 * Pros: Excellent cache locality (contiguous memory).
 * Cons: Occasional resizing pauses. Unused reserved memory capacity.
 */

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>

class StackArray {
private:
    vector<T> data;

public:
    // Pushes an element onto the stack.
    void push(T value) {
        data.push_back(value);
    }
    
    // Removes the top element. Throws error if empty.
    void pop() {
        if (isEmpty()) {
            throw out_of_range("Stack Underflow.");
        }
        data.pop_back();
    }
    
    // Returns the top element without removing it.
    T top() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty.");
        }
        return data.back();
    }

    // Returns true if the stack contains no elements.
    bool isEmpty() {
        return data.empty();
    }
    
    // Returns the number of elements in the stack.
    int size() {
        return data.size();
    }
};

int main() {
    try {
        StackArray<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        
        cout << "Top element is: " << s.top() << endl; // 3
        
        s.pop();
        cout << "Top element after pop is: " << s.top() << endl; // 2
        
        s.pop();
        s.pop();
        
        cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

        // Trigger exception
        // s.pop(); 

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}