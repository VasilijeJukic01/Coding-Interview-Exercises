using dict = vector<string>;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    int index = -1;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode();
    }

    ~Trie() {
        destroy(root);
    }

    void destroy(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                destroy(node->children[i]);
            }
        }
        delete node;
    }

    void insert(string& word, int index) {
        TrieNode* curr = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
            curr->index = index;
        }
    }

    int search(string& word) {
        TrieNode* curr = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                return curr->index;
            }
            curr = curr->children[word[i] - 'a'];
        }
        return curr->index;
    }
};

class Solution {
    Trie trie;
public:
    vector<int> stringIndices(dict& wordsContainer, dict& wordsQuery) {
        vector<array<int, 2>> sorted;
        for (int i = 0; i < wordsContainer.size(); i++) {
            int size = wordsContainer[i].size();
            sorted.push_back({size, i});
        }

        sort(sorted.rbegin(), sorted.rend());

        for (int i = 0; i < sorted.size(); i++) {
            int index = sorted[i][1];
            trie.insert(wordsContainer[index], index);
        }

        vector<int> result;
        for (auto& word : wordsQuery) {
            int index = trie.search(word);
            if (index == -1) result.push_back(sorted.back()[1]);
            else result.push_back(index);
        }

        return result;
    }
};