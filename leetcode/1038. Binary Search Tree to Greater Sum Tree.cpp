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
    void updateTree(TreeNode* root, int& acc) {
        if (root == nullptr) return;

        updateTree(root->right, acc);
        acc += root->val;
        root->val = acc;
        updateTree(root->left, acc);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int accumulator = 0;
        updateTree(root, accumulator);
        return root;
    }
};