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
    void dfs(TreeNode* root, vector<int> &v, int lvl) {
        if (root == nullptr) return;
        
        if (lvl >= v.size()) {
            v.push_back(root->val);
        }
        else if (root->val > v[lvl]) v[lvl] = root->val;

        dfs(root->left, v, lvl + 1);
        dfs(root->right, v, lvl + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        dfs(root, v, 0);

        return v;
    }
};