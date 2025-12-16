/*
 * Implementation of Two Stacks sharing a single array.
 * 
 * Strategy:
 * - Stack 1 starts at index 0 and grows upwards.
 * - Stack 2 starts at index n-1 and grows downwards.
 * - Overflow occurs only when top1 and top2 meet.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    // Stack 1 Operations
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            throw overflow_error("Stack Overflow: Array is full.");
        }
    }

    void pop1() {
        if (top1 >= 0) {
            top1--;
        } else {
            throw underflow_error("Stack 1 Underflow");
        }
    }

    int peek1() {
        if (top1 >= 0) return arr[top1];
        throw underflow_error("Stack 1 is Empty");
    }

    // Stack 2 Operations
    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            throw overflow_error("Stack Overflow: Array is full.");
        }
    }

    void pop2() {
        if (top2 < size) {
            top2++;
        } else {
            throw underflow_error("Stack 2 Underflow");
        }
    }

    int peek2() {
        if (top2 < size) return arr[top2];
        throw underflow_error("Stack 2 is Empty");
    }
};

int main() {
    try {
        TwoStacks ts(5);
        
        ts.push1(5);
        ts.push2(10);
        ts.push2(15);
        ts.push1(11);
        ts.push2(7);
        
        cout << "Stack 1 Top: " << ts.peek1() << endl;
        cout << "Stack 2 Top: " << ts.peek2() << endl;
        
        // This should throw overflow because size is 5 and we added 5 elements
        // ts.push1(40); 

    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}