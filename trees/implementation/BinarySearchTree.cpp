/*
 * Binary Search Tree (BST) Implementation
 * 
 * Logic: For every node, left < node < right.
 * Time Complexity: O(log n) if balanced, O(n) if skewed.
 * Space Complexity: O(h) for all operations, where h is height.
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }
    
    bool search(int val) {
        return search(root, val);
    }
    
    void remove(int val) {
        root = remove(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

private:
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        return (val < node->data) ? search(node->left, val) : search(node->right, val);
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            // Case 1 & 2: 0 or 1 child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: 2 children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    tree.insert(50); tree.insert(30); tree.insert(70);
    tree.insert(20); tree.insert(40); tree.insert(60);
    
    cout << "Inorder Traversal: ";
    tree.inorder(); // 20 30 40 50 60 70

    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    
    tree.remove(30);
    cout << "After removing 30: ";
    tree.inorder();

    return 0;
}