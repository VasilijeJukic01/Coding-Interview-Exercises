class Node {
public:
    vector<Node*> children;
    bool endOfWord;
    int val;

    Node() : children(26, nullptr), val(0), endOfWord(false) {}
};

class MapSum {
public:
    Node* root;

    MapSum() {
        this->root = new Node();
    }
    
    void insert(string key, int val) {
        Node* curr = root;
        for (int i = 0; i < key.size(); i++) {
            if (curr->children[key[i] - 'a'] == nullptr) {
                curr->children[key[i] - 'a'] = new Node();
            }
            curr = curr->children[key[i] - 'a'];
        }
        curr->endOfWord = true;
        curr->val = val;
    }

    void sumPaths(Node* root, int &total) {
        if (root->endOfWord) total += root->val;

        for (int i = 0; i < 26; i++) {
            if (root->children[i] == nullptr) continue;
            sumPaths(root->children[i], total);
        }
    }
    
    int sum(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->children[prefix[i] - 'a'] == nullptr) return 0;
            curr = curr->children[prefix[i] - 'a'];
        }
        
        int total = 0;
        sumPaths(curr, total);

        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */