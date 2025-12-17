/*
* Double-Ended Queue (Deque) using Doubly Linked List.
 * 
 * Supports: push_front, push_back, pop_front, pop_back.
 * Time Complexity: All O(1).
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node *front, *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!front) front = rear = newNode;
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (!rear) front = rear = newNode;
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (front) front->prev = nullptr;
        else rear = nullptr;
        delete temp;
    }

    void deleteRear() {
        if (!rear) return;
        Node* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = nullptr;
        else front = nullptr;
        delete temp;
    }

    int getFront() {
        return front ? front->data : -1;
    }
    
    int getRear() {
        return rear ? rear->data : -1;
    }
};

int main() {
    Deque d;
    d.insertRear(10);
    d.insertFront(20);
    d.insertRear(30);
    // Deque is now: 20 <-> 10 <-> 30
    
    cout << "Front: " << d.getFront() << " | Rear: " << d.getRear() << endl;
    d.deleteFront();
    
    cout << "New Front: " << d.getFront() << endl;
    
    return 0;
}