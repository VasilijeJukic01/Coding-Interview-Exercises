class Node {
public:
    vector<Node*> children;
    bool endOfWord;

    Node() : children(26, nullptr), endOfWord(false) {}
};

class Trie {
public:
    Node* root;
    int m, n;
    vector<string> v;

    vector<int> x = {1, 0, -1, 0};
    vector<int> y = {0, 1, 0, -1};

    Trie (int m, int n) {
        this->root = new Node();
        this->m = m;
        this->n = n;
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

    bool isSafe(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void search(Node* root, vector<vector<char>>& board, int i, int j, string& word) {
        if (root->endOfWord) {
            root->endOfWord = false;
            v.push_back(word);
        }

        char ch = board[i][j];
        board[i][j] = '@';

        for (int k = 0; k < 4; k++) {
            int I = i + y[k];
            int J = j + x[k];
            if (!isSafe(I, J) || board[I][J] == '@') continue;

            if (root->children[board[I][J] - 'a']) {
                word.push_back(board[I][J]);
                search(root->children[board[I][J] - 'a'], board, I, J, word);
                // Backtrack
                word.pop_back();
            }
        }

        board[i][j] = ch;
    }

    vector<string> solve(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->children[board[i][j] - 'a'] == nullptr) continue;
                string word = "";
                word.push_back(board[i][j]);
                search(root->children[board[i][j] - 'a'], board, i, j, word);
            }
        }

        return v;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(board.size(), board[0].size());

        for (int i = 0; i < words.size(); i++) {
            trie->insert(words[i]);
        }

        return trie->solve(board, words);
    }
};