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
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;
        if (root->val != subRoot->val) return false;

        bool leftCheck = isSameTree(root->left, subRoot->left);
        bool rightCheck = isSameTree(root->right, subRoot->right);

        return leftCheck && rightCheck;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if (isSameTree(root, subRoot)) return true;

        bool leftCheck = isSubtree(root->left, subRoot);
        bool rightCheck = isSubtree(root->right, subRoot);

        return leftCheck || rightCheck;
    }
};