class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
public:
    Node* root;

    Trie() {
        this->root = new Node();
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
            if (curr->children[word[i] - 'a'] == nullptr) return false;
            curr = curr->children[word[i] - 'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->children[prefix[i] - 'a'] == nullptr) return false;
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */