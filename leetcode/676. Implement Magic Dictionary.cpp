class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(26, nullptr), endOfWord(false) {}
};

class MagicDictionary {
public:
   Node* root;

   MagicDictionary () {
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

   void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            insert(dictionary[i]);
        }
   }

    bool search(Node* root, string word, int index, bool skipUsed) {
        if (index == word.size()) return skipUsed && root->endOfWord;
        
        if (!skipUsed) {
            for (int i = 0; i < 26; i++) {
                if (i == word[index] - 'a') continue;
                if (root->children[i] == nullptr) continue;
                
                if (search(root->children[i], word, index + 1, true)) return true;
            }
        }

        if (root->children[word[index] - 'a'] == nullptr) return false;
    
        return search(root->children[word[index] - 'a'], word, index + 1, skipUsed);
   }

   bool search(string searchWord) {
        return search(root, searchWord, 0, false);
   }

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */