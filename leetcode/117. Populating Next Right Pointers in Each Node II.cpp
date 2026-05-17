/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* root, vector<Node*>& levels, int d) {
        if (root == nullptr) return;

        if (d >= levels.size()) levels.push_back(root);
        else {
            levels[d]->next = root;
            levels[d] = root;
        }

        dfs(root->left, levels, d + 1);
        dfs(root->right, levels, d + 1);
    }

    Node* connect(Node* root) {
        vector<Node*> levels;
        dfs(root, levels, 0);
        return root;
    }
};