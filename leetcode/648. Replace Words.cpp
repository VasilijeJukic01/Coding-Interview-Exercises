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

    string search(string word) {
        Node* curr = root;
        string wordRoot = "";
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) break;
            wordRoot += word[i];
            curr = curr->children[word[i] - 'a'];
            if (curr->endOfWord) return wordRoot;
        }

        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();

        for (int i = 0; i < dictionary.size(); i++) {
            trie->insert(dictionary[i]);
        }

        stringstream ss;
        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' || i == sentence.size() - 1) {
                if (i == sentence.size() - 1) word += sentence[i];

                string wordRoot = trie->search(word);
                if (wordRoot == "") ss << word;
                else ss << wordRoot;

                if (i != sentence.size() - 1) ss << " ";

                word = "";
            }
            else word += sentence[i];
        }

        return ss.str();
    }
};