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
    void dfs(TreeNode* root, vector<int>& levelSum, int level) {
        if (root == nullptr) return;
        
        if (level >= levelSum.size()) {
            levelSum.push_back(root->val);
        }
        else levelSum[level] += root->val;

        dfs(root->left, levelSum, level + 1);
        dfs(root->right, levelSum, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> levelSum;
        dfs(root, levelSum, 0);

        int maxSum = INT_MIN;
        int level = 0;
        for (int i = 0; i < levelSum.size(); i++) {
            if (levelSum[i] > maxSum) {
                maxSum = levelSum[i];
                level = i + 1;
            }
        }

        return level;
    }
};