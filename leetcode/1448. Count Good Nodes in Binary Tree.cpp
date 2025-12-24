/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int &total, int maximum) {
        if (root == nullptr) return;

        if (root->val >= maximum) total++;

        solve(root->left, total, max(maximum, root->val));
        solve(root->right, total, max(maximum, root->val));
    }

    int goodNodes(TreeNode* root) {
        int total = 0;

        solve(root, total, root->val);

        return total;
    }
};