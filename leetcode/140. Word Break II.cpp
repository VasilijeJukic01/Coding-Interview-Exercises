struct TrieNode {
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->endOfWord = true;
    }

    void search(TrieNode* root, int index, string& s, string& curr, vector<string>& result) {
        if (index == s.size()) {
            if (root->endOfWord) {
                result.push_back(curr);
            }
            return;
        }

        if (root->endOfWord) {
            curr += ' ';
            search(this->root, index, s, curr, result);
            // Backtrack
            curr.pop_back();
        }

        if (root->children[s[index] - 'a']) {
            curr += s[index];
            search(root->children[s[index] - 'a'], index + 1, s, curr, result);
            // Backtrack
            curr.pop_back();
        }
    }

    void search(string& s, vector<string>& result) {
        string curr = "";
        search(root, 0, s, curr, result);
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& word : wordDict) {
            trie.insert(word);
        }

        vector<string> result;
        trie.search(s, result);

        return result;
    }
};