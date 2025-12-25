/*
 * AVL Tree Implementation
 *
 * Logic: Strict balancing via Balance Factor (BF = height_L - height_R).
 * Complexity: O(log n) guaranteed for Search, Insert, Delete.
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;
    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {

    int getHeight(Node* n) {
        if (n == nullptr) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == nullptr) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* getMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        else return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && val < node->left->data) return rotateRight(node);
        // RR Case
        if (balance < -1 && val > node->right->data) return rotateLeft(node);
        // LR Case
        if (balance > 1 && val > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // RL Case
        if (balance < -1 && val < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node* remove(Node* root, int val) {
        // 1. Standard BST Deletion
        if (!root) return root;

        if (val < root->data) {
            root->left = remove(root->left, val);
        }
        else if (val > root->data) {
            root->right = remove(root->right, val);
        }
        else {
            // Node with only one child or no child
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;

                // No child case
                if (!temp) {
                    temp = root;
                    root = nullptr;
                }
                // One child case
                else *root = *temp;
                delete temp;
            }
            else {
                // Node with two children: get inorder successor
                Node* temp = getMinValueNode(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }

        if (!root) return root;

        // 2. Update Height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // 3. Rebalance the node
        int balance = getBalance(root);

        // LL Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rotateRight(root);
        // LR Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        // RR Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return rotateLeft(root);
        // RL Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    AVLTree tree;
    Node* root = nullptr;

    root = tree.insert(root, 10);
    root = tree.insert(root, 20);
    root = tree.insert(root, 30);
    root = tree.insert(root, 40);
    root = tree.insert(root, 50);
    root = tree.insert(root, 25);

    cout << "Inorder traversal: ";
    tree.inorder(root); // 10 20 25 30 40 50
    cout << endl;

    root = tree.remove(root, 30);

    cout << "Inorder after deleting 30: ";
    tree.inorder(root); // 10 20 25 40 50
    cout << endl;

    return 0;
}