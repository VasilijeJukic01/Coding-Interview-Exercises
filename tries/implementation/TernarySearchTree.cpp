/*
 * Ternary Search Tree (TST) Implementation
 *
 * Concepts:
 * - Each node has 3 children: Left (smaller), Equal (next char), Right (larger).
 * - Space efficient compared to standard Tries (no empty null pointers for unused chars).
 * - Time Complexity: O(L) best case, but can degrade to O(L*Alphabet) depending on insertion order.
 */

#include <iostream>
#include <string>

using namespace std;

struct TSTNode {
    char data;
    bool isEndOfWord;
    TSTNode *left, *eq, *right;

    TSTNode(char c) : data(c), isEndOfWord(false), left(nullptr), eq(nullptr), right(nullptr) {}
};

class TernarySearchTree {
private:
    TSTNode* root;

    TSTNode* insert(TSTNode* node, string& word, int index) {
        char c = word[index];

        if (!node) node = new TSTNode(c);

        if (c < node->data) {
            node->left = insert(node->left, word, index);
        }
        else if (c > node->data) {
            node->right = insert(node->right, word, index);
        }
        else {
            // Character matches current node
            if (index < word.length() - 1) {
                node->eq = insert(node->eq, word, index + 1);
            }
            else node->isEndOfWord = true;
        }
        return node;
    }

    bool search(TSTNode* node, string& word, int index) {
        if (!node) return false;

        char c = word[index];

        if (c < node->data) {
            return search(node->left, word, index);
        }
        if (c > node->data) {
            return search(node->right, word, index);
        }
        if (index == word.length() - 1) {
            return node->isEndOfWord;
        }
        return search(node->eq, word, index + 1);
    }

    void clear(TSTNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->eq);
        clear(node->right);
        delete node;
    }

public:
    TernarySearchTree() : root(nullptr) {}

    ~TernarySearchTree() {
        clear(root);
    }

    void insert(string word) {
        if (word.empty()) return;
        root = insert(root, word, 0);
    }

    bool search(string word) {
        if (word.empty()) return false;
        return search(root, word, 0);
    }
};

int main() {
    TernarySearchTree tst;
    tst.insert("cat");
    tst.insert("cats");
    tst.insert("bug");
    tst.insert("up");

    cout << boolalpha;
    cout << "Search 'cat': " << tst.search("cat") << endl;   // true
    cout << "Search 'cats': " << tst.search("cats") << endl; // true
    cout << "Search 'bu': " << tst.search("bu") << endl;     // false

    return 0;
}