/*
 * Stack Implementation using a Singly Linked List.
 * 
 * Pros:
 * - Dynamic size: The stack can grow and shrink as needed (limited only by memory).
 * - Constant time operations: Push and Pop are O(1) without the occasional O(n) resize penalty of arrays.
 * 
 * Cons:
 * - Extra memory overhead: Requires storage for pointers.
 * - Cache locality: Nodes are not necessarily contiguous in memory, leading to potential cache misses compared to arrays.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class StackLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    StackLinkedList() : head(nullptr), count(0) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) throw logic_error("Stack Underflow.");
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    T top() {
        if (isEmpty()) {
            throw logic_error("Stack is empty.");
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }
};

int main() {
    try {
        StackLinkedList<int> s;
        
        cout << "Pushing 10, 20, 30..." << endl;
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Current top: " << s.top() << endl; // 30
        cout << "Stack size: " << s.size() << endl; // 3

        cout << "Popping..." << endl;
        s.pop();
        cout << "New top: " << s.top() << endl; // 20

        s.pop();
        s.pop();

        cout << "Is empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

        // This should throw an exception
        // s.pop(); 

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}