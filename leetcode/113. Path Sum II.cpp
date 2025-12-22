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
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& v, vector<int> curr, int sum) {
        if (root == nullptr) return;

        curr.push_back(root->val);
        sum += root->val;
        if (sum == targetSum && !root->left && !root->right) {
            v.push_back(curr);
        }

        dfs(root->left, targetSum, v, curr, sum);
        dfs(root->right, targetSum, v, curr, sum);

        // Backtrack
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        dfs(root, targetSum, v, {}, 0);

        return v;
    }
};