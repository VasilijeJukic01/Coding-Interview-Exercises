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
    void dfs(TreeNode* root, int curr, int& d, int& x) {
        if (root == nullptr) return;

        dfs(root->left, curr + 1, d, x);
        dfs(root->right, curr + 1, d, x);
        if (curr > d) {
            d = curr;
            x = root->val;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int d = 0, x = root->val;
        dfs(root, 0, d, x);
        return x;
    }
};