#include <iostream>

using namespace std;

// Structure
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

// Insertion
void addLeft(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void addRight(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* itr = head;
    while (itr->next != nullptr) {
        itr = itr->next;
    }
    itr->next = newNode;
}

void addTo(Node*& head, int data, int index) {
    if (index < 1) {
        cerr << "Error: Invalid index " << index << ". Must be 1 or greater." << endl;
        return;
    }
    if (index == 1) {
        addLeft(head, data);
        return;
    }

    Node* itr = head;

    for (int i = 1; i < index - 1 && itr; i++) {
        itr = itr->next;
    }

    if (itr == nullptr) {
        cerr << "Error: Index " << index << " is out of bounds." << endl;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = itr->next;
    itr->next = newNode;
}

void addSortedIncr(Node*& head, int data) {
    Node* newNode = new Node(data);
	
    if (head == nullptr || data < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
	
    Node* itr = head;
    while (itr->next && itr->next->data < data) {
        itr = itr->next;
    }
	
    newNode->next = itr->next;
    itr->next = newNode;
}

void addSortedDecr(Node*& head, int data) {
    Node* newNode = new Node(data);
	
    if (head == nullptr || data > head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
	
    Node* itr = head;
    while (itr->next && itr->next->data > data) {
        itr = itr->next;
    }
	
    newNode->next = itr->next;
    itr->next = newNode;
}

// Deletion
void deleteAt(Node*& head, int index) {
    if (head == nullptr) {
        cerr << "Error: Cannot delete from an empty list." << endl;
        return;
    }
    if (index < 1) {
        cerr << "Error: Invalid index " << index << ". Must be 1 or greater." << endl;
        return;
    }

    Node* temp = head;
    if (index == 1) {
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    for (int i = 1; i < index && temp; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cerr << "Error: Index " << index << " is out of bounds." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void deleteNode(Node*& head, int data) {
    if (head == nullptr) {
        cerr << "Error: Cannot delete from an empty list." << endl;
        return;
    }

    Node* temp = head;

    if (head->data == data) {
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cerr << "Element " << data << " not found in the list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Printing
void printListIter(Node* head) {
    Node* itr = head;
    while (itr) {
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << endl;
}

void printListRec(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printListRec(head->next);
}

void printListReverseRec(Node* head) {
    if (head == nullptr) return;
	
    printListReverseRec(head->next);
    cout << head->data << " ";
}

// Reversing
void reverse(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr;

    addSortedDecr(head, 7);
    addSortedDecr(head, 11);
    addSortedDecr(head, 32);
    addSortedDecr(head, 4);
    addSortedDecr(head, 2);
    addSortedDecr(head, 7);

    cout << "Original list (sorted descending): ";
    printListRec(head);

    cout << "Deleting element at index 1 (value 32): ";
    deleteAt(head, 1);
    printListIter(head);

    cout << "Reversing the list: ";
    reverse(head);
    printListIter(head);
    
    cout << "Deleting node with value 4: ";
    deleteNode(head, 4);
    printListIter(head);

    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    return 0;
}
