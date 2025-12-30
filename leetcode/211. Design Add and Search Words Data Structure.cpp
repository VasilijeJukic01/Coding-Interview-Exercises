class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(26, nullptr), endOfWord(false) {}
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->endOfWord = true;
    }

    bool search(string word, Node* root) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (root->children[j] == nullptr) continue;
                    if (search(word.substr(i + 1), root->children[j])) return true;
                }
                return false;
            }
            else {
                if (root->children[word[i] - 'a'] == nullptr) return false;
                root = root->children[word[i] - 'a'];
            }
        }
        return root->endOfWord;
    }
    
    bool search(string word) {
        return search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */