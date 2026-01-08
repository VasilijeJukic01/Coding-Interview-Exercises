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
    void sum(TreeNode* root, long long &total) {
        if (root == nullptr) return;
        total += root->val;
        sum(root->left, total);
        sum(root->right, total);
    }

    long long dfs(TreeNode* root, long long &best, long long total) {
        if (root == nullptr) return 0;

        long long leftSum = dfs(root->left, best, total);
        long long rightSum = dfs(root->right, best, total);
        long long firstOption = rightSum * (total - rightSum);
        long long secondOption = leftSum * (total - leftSum);

        best = max(best, max(firstOption, secondOption));

        return rightSum + leftSum + root->val;
    }

    int maxProduct(TreeNode* root) {
        long long total = 0;
        long long best = 0;
        sum(root, total);
        dfs(root, best, total);

        return best % (1000000000 + 7);
    }
};