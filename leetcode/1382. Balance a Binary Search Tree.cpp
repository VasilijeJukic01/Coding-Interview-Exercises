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
    void dfs(TreeNode* root, vector<int> &v) {
        if (root == nullptr) return;

        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }

    TreeNode* build(vector<int> &v, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(v, start, mid - 1);
        root->right = build(v, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;

        dfs(root, v);

        return build(v, 0, v.size() - 1);
    }
};