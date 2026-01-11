/*
 * Standard Trie (Prefix Tree) Implementation
 *
 * Concepts:
 * - Each node represents a character.
 * - Suitable for prefix-based searches (Autocomplete, Spell Check).
 * - Time Complexity: O(L) for insert/search/delete, where L is string length.
 * - Space Complexity: O(ALPHABET_SIZE * N * L).
 */

#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (children[i]) delete children[i];
        }
    }
};

class Trie {
private:
    TrieNode* root;

    bool removeUtil(TrieNode* node, string& word, int depth) {
        if (!node) return false;

        // Base case: If last character of key is being processed
        if (depth == word.size()) {
            if (!node->isEndOfWord) return false; // Word not found

            node->isEndOfWord = false; // Unmark leaf

            // If node has no children, it can be deleted
            return isEmpty(node);
        }

        int index = word[depth] - 'a';
        if (removeUtil(node->children[index], word, depth + 1)) {
            // Delete the child node
            delete node->children[index];
            node->children[index] = nullptr;

            // Return true if current node is empty and not a word end
            return !node->isEndOfWord && isEmpty(node);
        }

        return false;
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) return false;
        }
        return true;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return curr != nullptr && curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return true;
    }

    void remove(string word) {
        removeUtil(root, word, 0);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    cout << boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl; // true
    cout << "Search 'app': " << trie.search("app") << endl;     // true

    trie.remove("apple");
    cout << "Search 'apple' after delete: " << trie.search("apple") << endl; // false
    cout << "Search 'app' after delete: " << trie.search("app") << endl;     // true (should still exist)

    return 0;
}