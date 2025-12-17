/*
 * Queue Implementation using a Singly Linked List.
 *
 * Pros: Truly dynamic size, O(1) enqueue and dequeue.
 * Cons: Extra memory for pointers, not cache-friendly.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>

class QueueLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node *head, *tail;
    int count;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~QueueLinkedList() {
        while (!isEmpty()) dequeue();
    }

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) throw underflow_error("Queue Underflow.");
        Node* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        count--;
    }

    T front() {
        if (isEmpty()) throw underflow_error("Queue is empty.");
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
    QueueLinkedList<string> q;
    q.enqueue("First");
    q.enqueue("Second");

    cout << "Front: " << q.front() << " | Size: " << q.size() << endl;
    q.dequeue();

    cout << "New Front: " << q.front() << endl;

    return 0;
}