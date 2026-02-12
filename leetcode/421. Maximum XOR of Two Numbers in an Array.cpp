struct TrieNode {
    TrieNode* bits[2];

    TrieNode() {
        bits[0] = bits[1] = nullptr;
    }

    bool contains(int bit) {
        return bits[bit] != nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int n) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (curr->bits[bit] == nullptr) {
                curr->bits[bit] = new TrieNode();
            }
            curr = curr->bits[bit];
        }
    }

    int search(int n) {
        TrieNode* curr = root;
        int best = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (curr->contains(1 - bit)) {
                best |= (1 << i);
                curr = curr->bits[1 - bit];
            }
            else curr = curr->bits[bit];
        }
        return best;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        for (auto& n : nums) {
            trie->insert(n);
        }

        int currMax = 0;
        for (auto& n : nums) {
            currMax = max(currMax, trie->search(n));
        }

        return currMax;
    }
};