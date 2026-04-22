struct TrieNode {
    vector<TrieNode*> children;
    bool endOfWord;
    vector<int> indices;

    TrieNode() : children(26, nullptr), endOfWord(false) {}

    ~TrieNode() {
        for (auto& child : children) {
            delete child;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string& w, int index) {
        TrieNode* curr = root;
        for (int i = 0; i < w.size(); i++) {
            if (curr->children[w[i] - 'a'] == nullptr) {
                curr->children[w[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[w[i] - 'a'];
        }
        curr->endOfWord = true;
        curr->indices.push_back(index);
    }

    void dfs(TrieNode* root, string& w, int i, int skips, vector<int>& res) {
        if (i == w.size()) {
            if (root->endOfWord) {
                for (int index : root->indices) {
                    res.push_back(index);
                }
            }
            return;
        }

        if (skips > 0) {
            for (int k = 0; k < 26; k++) {
                if (w[i] - 'a' == k) continue;
                if (root->children[k] == nullptr) continue;

                dfs(root->children[k], w, i + 1, skips - 1, res);
            }
        }
        if (root->children[w[i] - 'a'] != nullptr) {
            dfs(root->children[w[i] - 'a'], w, i + 1, skips, res);
        }
    }

    vector<int> search(string& w) {
        vector<int> res;
        dfs(root, w, 0, 2, res);
        return res;
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie trie;
        for (int i = 0; i < queries.size(); i++) {
            trie.insert(queries[i], i);
        }

        unordered_set<int> s;
        for (auto& word : dictionary) {
            vector<int> res = trie.search(word);
            for (auto& index : res) {
                s.insert(index);
            }
        }

        vector<string> result;
        for (int i = 0; i < queries.size(); i++) {
            if (s.find(i) != s.end()) {
                result.push_back(queries[i]);
            }
        }
        return result;
    }
};