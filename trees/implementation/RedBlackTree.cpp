/*
 * Red-Black Tree Implementation
 *
 * Rules:
 * 1. Nodes are RED or BLACK.
 * 2. Root is always BLACK.
 * 3. TNULL (leaves) are BLACK.
 * 4. RED nodes cannot have RED children.
 * 5. Every path from a node to its leaves has the same number of BLACK nodes.
 */

#include <iostream>

using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Node *parent, *left, *right;
    Color color;
};

class RedBlackTree {
private:
    Node* root;
    // Sentinel node
    Node* TNULL;

    void preOrder(Node* node) {
        if (node != TNULL) {
            cout << node->data << (node->color == RED ? "(R) " : "(B) ");
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != TNULL) y->left->parent = x;
        y->parent = x->parent;

        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != TNULL) x->right->parent = y;
        x->parent = y->parent;

        if (y->parent == nullptr) root = x;
        else if (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;

        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* k) {
        Node* u;
        while (k->parent->color == RED) {
            // If parent is the right child of the grandparent
            if (k->parent == k->parent->parent->right) {
                // Uncle
                u = k->parent->parent->left;
                // Case 1: Uncle is Red
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                // Uncle is Black
                else {
                    // Case 2: Triangle (RL)
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    // Case 3: Line (RR)
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
            // If parent is the left child of the grandparent
            else {
                // Uncle
                u = k->parent->parent->right;
                // Case 1: Uncle is Red
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                }
                // Uncle is Black
                else {
                    // Case 2: Triangle (LR)
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    // Case 3: Line (LL)
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        // Set root to black
        root->color = BLACK;
    }

    // Replaces subtree u with v
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    void fixDelete(Node* x) {
        Node* s;
        while (x != root && x->color == BLACK) {
            // Replacing node is the left child of its parent
            if (x == x->parent->left) {
                // Sibling
                s = x->parent->right;
                // Case 1: Sibling is Red
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }
                // Case 2: Sibling is black and has two black children
                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    // Case 3: Sibling's outer child is black
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }
                    // Case 4: Sibling's outer child is red
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            // Replacing node is the right child of its parent
            else {
                s = x->parent->left;
                // Case 1: Sibling is Red
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }
                // Case 2: Sibling is black and has two black children
                if (s->right->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    // Case 3: Sibling's outer child is black
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }
                    // Case 4: Sibling's outer child is red
                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = BLACK;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    Node* minimum(Node* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    void insert(int key) {
        Node* node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) x = x->left;
            else x = x->right;
        }

        node->parent = y;
        if (y == nullptr) root = node;
        else if (node->data < y->data) y->left = node;
        else y->right = node;

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }
        if (node->parent->parent == nullptr) return;

        fixInsert(node);
    }

    void deleteNode(int data) {
        Node* z = TNULL;
        Node *x, *y;
        Node* node = this->root;

        while (node != TNULL) {
            if (node->data == data) z = node;
            if (node->data <= data) node = node->right;
            else node = node->left;
        }

        if (z == TNULL) return;

        y = z;
        Color yOriginalColor = y->color;
        if (z->left == TNULL) {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            transplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) x->parent = y;
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (yOriginalColor == BLACK) fixDelete(x);
    }

    void printTree() {
        preOrder(this->root); cout << endl;
    }
};

int main() {
    RedBlackTree bst;
    bst.insert(8);
    bst.insert(18);
    bst.insert(5);
    bst.insert(15);
    bst.insert(17);
    bst.insert(25);
    bst.insert(40);
    bst.insert(80);

    cout << "Tree after insertion: ";
    bst.printTree();

    bst.deleteNode(25);
    cout << "Tree after deleting 25: ";
    bst.printTree();

    return 0;
}