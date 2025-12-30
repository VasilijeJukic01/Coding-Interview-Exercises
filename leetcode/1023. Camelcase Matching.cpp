class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(128, nullptr), endOfWord(false) {}
};

class Trie {
public:
    Node* root;

    Trie() {
        this->root = new Node();
    }
    
    void insert(string pattern) {
        Node* curr = root;
        for (int i = 0; i < pattern.size(); i++) {
            if (curr->children[pattern[i]] == nullptr) {
                curr->children[pattern[i]] = new Node();
            }
            curr = curr->children[pattern[i]];
        }
        curr->endOfWord = true;
    }

    bool capital(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    
    bool validate(string word) {
        Node* curr = root;

        int index = 0;
        while (index < word.size()) {
            if (curr->children[word[index]]) {
                curr = curr->children[word[index]];
                index++;
            }
            else {
                while (index < word.size()) {
                    // If letter is lower and matches root -> valid break;
                    if (!capital(word[index]) && curr->children[word[index]]) break;
                    // If letter is lower and doesnt match root -> valid, move index
                    else if (!capital(word[index]) && !curr->children[word[index]]) index++;
                    // If letter is upper and matches root -> valid, move both
                    else if (capital(word[index]) && curr->children[word[index]]) break;
                    // If letter is upper and doesnt match root -> invalid
                    else return false;
                }
            }
        }

        return curr->endOfWord;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        Trie* trie = new Trie();

        trie->insert(pattern);

        for (int i = 0; i < queries.size(); i++) {
            answer.push_back(trie->validate(queries[i]));
        }

        return answer;
    }
};