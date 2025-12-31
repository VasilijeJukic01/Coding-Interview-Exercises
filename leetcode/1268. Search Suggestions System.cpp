class Node {
public:
    vector<Node*> children;
    vector<string> cache;

    Node() : children(26, nullptr) {}
};

class Trie {
public:
    Node* root;

    Trie () {
        this->root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];

            if (curr->cache.size() < 3) {
                curr->cache.push_back(word);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> sugg;
        Trie* trie = new Trie();

        for (int i = 0; i < products.size(); i++) {
            trie->insert(products[i]);
        }

        bool deadEnd = false;
        Node* curr = trie->root;
        for (int i = 0; i < searchWord.size(); i++) {
            if (!deadEnd && curr->children[searchWord[i] - 'a']) {
                curr = curr->children[searchWord[i] - 'a'];
                sugg.push_back(curr->cache);
            }
            else {
                deadEnd = true;
                sugg.push_back({});
            }
        }

        return sugg;
    }
};