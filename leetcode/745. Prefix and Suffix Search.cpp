class Node {
public:
    vector<Node*> children;
    int weight;

    Node() : children(27, nullptr), weight(-1) {}
};

class WordFilter {
    Node* root;

    void insert(string word, int index) {
        Node* curr = root;
        curr->weight = index; 
        
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == nullptr) {
                curr->children[word[i] - 'a'] = new Node();
            }
            curr = curr->children[word[i] - 'a'];
            curr->weight = index;
        }
    }

public:
    WordFilter(vector<string>& words) {
        root = new Node();
        
        for (int k = 0; k < words.size(); k++) {
            string word = words[k];
            int n = word.size();
            for (int i = 0; i <= n; i++) {
                string key = word.substr(i) + "{" + word;
                insert(key, k);
            }
        }
    }
    
    int f(string pref, string suff) {
        Node* curr = root;
        string key = suff + "{" + pref;
        
        for (int i = 0; i < key.size(); i++) {
            if (!curr->children[key[i] - 'a']) return -1;
            curr = curr->children[key[i] - 'a'];
        }
        
        return curr->weight;
    }
};