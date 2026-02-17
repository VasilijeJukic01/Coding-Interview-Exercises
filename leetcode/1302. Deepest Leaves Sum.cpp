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
    void dfs(TreeNode* root, vector<int>& v, int d) {
        if (root == nullptr) return;

        if (d >= v.size()) {
            v.push_back(root->val);
        }
        else v[d] += root->val;
        
        dfs(root->left, v, d + 1);
        dfs(root->right, v, d + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        vector<int> v;
        dfs(root, v, 0);
        return v.back();
    }
};