class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
public:
    Node* root;

    Trie () {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            if (!curr->children[word[i] - 'a']->endOfWord) {
                return false;
            }
            curr = curr->children[word[i] - 'a'];
        }
        return curr->endOfWord;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();

        for (int i = 0; i < words.size(); i++) {
            trie->insert(words[i]);
        }

        int maxLen = 0;
        string best = "";

        for (int i = 0; i < words.size(); i++) {
            if (trie->search(words[i]) && words[i].size() >= maxLen) {
                if (words[i].size() == maxLen && words[i] < best) {
                    best = words[i];
                    continue;
                }
                else if (words[i].size() > maxLen) {
                    maxLen = words[i].size();
                    best = words[i];
                }
            }
        }

        return best;
    }
};