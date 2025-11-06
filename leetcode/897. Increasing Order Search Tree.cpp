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
    void createBST(TreeNode* &curr, TreeNode* root) {
        if (root == nullptr) return;
        createBST(curr, root->left);
        curr->right = root;
        root->left = nullptr; 
        curr = curr->right;
        createBST(curr, root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* stub = new TreeNode(-1);
        TreeNode* curr = stub;
        createBST(curr, root);
        return stub->right;
    }
};