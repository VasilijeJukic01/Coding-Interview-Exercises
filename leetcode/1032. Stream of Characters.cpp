class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node () : children(26, nullptr), endOfWord(false) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie () {
        this->root = new Node();
    }

    void insert(string& word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->endOfWord = true;
    }

    bool search(string& buffer) {
        Node* curr = root;
        for (int i = buffer.size() - 1; i >= 0; i--) {
            if (curr->children[buffer[i] - 'a'] == nullptr) return false;
            if (curr->children[buffer[i] - 'a']->endOfWord) return true;
            curr = curr->children[buffer[i] - 'a'];
        }
        return false;
    }
};

class StreamChecker {
public:
    Trie* trie;
    string buffer;

    StreamChecker(vector<string>& words) {
        this->trie = new Trie();

        for (string word : words) {
            reverse(word.begin(), word.end());
            trie->insert(word);
        }
    }
    
    bool query(char letter) {
        buffer.push_back(letter);
        return trie->search(buffer);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */