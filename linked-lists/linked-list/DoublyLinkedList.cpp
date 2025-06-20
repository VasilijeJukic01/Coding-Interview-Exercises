#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Insertion
void addToHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addToTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
	
    Node* itr = head;
    while (itr->next) {
        itr = itr->next;
    }
	
    itr->next = newNode;
    newNode->prev = itr;
}

void addTo(Node*& head, int data, int index) {
    if (index < 1) {
        cerr << "Error: Invalid index. Must be 1 or greater." << endl;
        return;
    }
    if (index == 1) {
        addToHead(head, data);
        return;
    }

    Node* itr = head;
    for (int i = 1; i < index - 1 && itr; ++i) {
        itr = itr->next;
    }

    if (itr == nullptr) {
        cerr << "Error: Index " << index << " is out of bounds." << endl;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = itr->next;
    newNode->prev = itr;
    if (itr->next) {
        itr->next->prev = newNode;
    }
    itr->next = newNode;
}


// Deletion
void deleteAt(Node*& head, int index) {
    if (head == nullptr) {
        cerr << "Error: Cannot delete from an empty list." << endl;
        return;
    }
    if (index < 1) {
        cerr << "Error: Invalid index. Must be 1 or greater." << endl;
        return;
    }

    Node* temp = head;
    if (index == 1) {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return;
    }

    for (int i = 1; i < index && temp; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cerr << "Error: Index " << index << " is out of bounds." << endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}


// Printing
void printForwardRec(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printForwardRec(head->next);
}

void printBackwardIter(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* itr = head;
	
    while (itr->next) {
        itr = itr->next;
    }
	
    while (itr) {
        cout << itr->data << " ";
        itr = itr->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addToHead(head, 5);
    addToHead(head, 7);
    addToHead(head, 2);
    addToTail(head, 9);
    addTo(head, 8, 2);

    cout << "List printed forward: ";
    printForwardRec(head);

    deleteAt(head, 3);

    cout << "List printed backward after deleting 3rd element: ";
    printBackwardIter(head);

    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;

    return 0;
}
