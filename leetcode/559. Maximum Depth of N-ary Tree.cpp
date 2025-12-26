/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, int &best, int depth) {
        if (root == nullptr) return;

        best = max(best, depth);

        for (int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i], best, depth + 1);
        }
    }

    int maxDepth(Node* root) {
        int best = 0;
        dfs(root, best, 1);

        return best;
    }
};