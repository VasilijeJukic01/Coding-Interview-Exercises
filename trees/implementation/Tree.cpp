/*
 * N-ary Tree Implementation
 * 
 * Logic:
 * - Nodes contain a vector of pointers to children.
 * - Deletion involves removing a node from its parent's list and cleaning up its subtree.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;

    Node(int x) : val(x) {}
};

class NaryTree {
public:
    Node* find(Node* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) return root;

        for (Node* child : root->children) {
            Node* res = find(child, key);
            if (res) return res;
        }
        return nullptr;
    }
    
    // In N-ary trees, we usually insert val as a child of a specific parentVal
    bool insert(Node* root, int parentVal, int newVal) {
        Node* parent = find(root, parentVal);
        if (parent) {
            parent->children.push_back(new Node(newVal));
            return true;
        }
        return false;
    }
    
    // Deletes the node with value key and its entire subtree
    Node* remove(Node* root, int key) {
        if (!root) return nullptr;
        
        if (root->val == key) {
            clear(root);
            return nullptr;
        }
        
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            if ((*it)->val == key) {
                clear(*it);
                root->children.erase(it);
                return root;
            }
            remove(*it, key);
        }
        return root;
    }
    
    int getHeight(Node* root) {
        if (!root) return -1;
        if (root->children.empty()) return 0;

        int maxHeight = 0;
        for (Node* child : root->children) {
            maxHeight = max(maxHeight, getHeight(child));
        }
        
        return 1 + maxHeight;
    }
    
    int getSize(Node* root) {
        if (!root) return 0;
        
        int count = 1;
        for (Node* child : root->children) {
            count += getSize(child);
        }
        return count;
    }
    
    void postorder(Node* root) {
        if (!root) return;
        
        for (Node* child : root->children) {
            postorder(child);
        }
        cout << root->val << " ";
    }
    
    void clear(Node* node) {
        if (!node) return;
        
        for (Node* child : node->children) {
            clear(child);
        }
        delete node;
    }
    
    void printLevelOrder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node* curr = q.front();
                q.pop();
                cout << curr->val << " ";
                for (Node* child : curr->children) q.push(child);
            }
            cout << " | ";
        }
        cout << endl;
    }
};

int main() {
    NaryTree tree;
    
    Node* root = new Node(1);

    // Build Tree
    //         1
    //      /  |  \
    //     2   3   4
    //    / \      |
    //   5   6     7
    tree.insert(root, 1, 2);
    tree.insert(root, 1, 3);
    tree.insert(root, 1, 4);
    tree.insert(root, 2, 5);
    tree.insert(root, 2, 6);
    tree.insert(root, 4, 7);

    cout << "Level Order: ";
    tree.printLevelOrder(root);

    cout << "Tree Size: " << tree.getSize(root) << endl;
    cout << "Tree Height: " << tree.getHeight(root) << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(root); // 5 6 2 3 7 4 1
    cout << endl;

    cout << "Deleting subtree starting at node 2..." << endl;
    tree.remove(root, 2);

    cout << "Level Order after deletion: ";
    tree.printLevelOrder(root); // 1 | 3 4 | 7 |
    
    tree.clear(root);

    return 0;
}