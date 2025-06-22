#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
	
    Node(int val) : data(val), next(nullptr) {}
};


void addToEmpty(Node*& tail, int data) {
    tail = new Node(data);
    tail->next = tail;
}

void addFront(Node*& tail, int data) {
    if (tail == nullptr) {
        addToEmpty(tail, data);
        return;
    }
	
    Node* newNode = new Node(data);
    newNode->next = tail->next;
    tail->next = newNode;
}

void addBack(Node*& tail, int data) {
    if (tail == nullptr) {
        addToEmpty(tail, data);
        return;
    }
	
    Node* newNode = new Node(data);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
	
    Node* head = tail->next;
    Node* itr = head;
    do {
        cout << itr->data << " ";
        itr = itr->next;
    } while (itr != head);
	
    cout << endl;
}

int main() {
    Node* tail = nullptr;

    addBack(tail, 1);
    addBack(tail, 3);
    addFront(tail, 8);

    cout << "Final list: ";
    printList(tail);

    if (tail) {
        Node* head = tail->next;
        tail->next = nullptr;
        
        Node* current = head;
        while(current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    return 0;
}
