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
    void dfs(TreeNode* root, vector<int>& result, int depth) {
        if (root == nullptr) return;

        if (depth >= result.size()) {
            result.push_back(root->val);
        }
        else result[depth] = root->val;
        
        dfs(root->left, result, depth + 1);
        dfs(root->right, result, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, result, 0);

        return result;
    }
};