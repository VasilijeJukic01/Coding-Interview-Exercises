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
    // {sum, counter}
    using p = pair<int, int>;

    p dfs(TreeNode* root, int& total) {
        if (root == nullptr) return {0, 0};

        p leftData = dfs(root->left, total);
        p rightData = dfs(root->right, total);

        int leftSum = leftData.first;
        int rightSum = rightData.first;
        int n = leftData.second + rightData.second + 1;

        int sum = leftSum + rightSum + root->val;
        if (sum / n == root->val) {
            total++;
        }

        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int total = 0;
        dfs(root, total);
        return total;
    }
};