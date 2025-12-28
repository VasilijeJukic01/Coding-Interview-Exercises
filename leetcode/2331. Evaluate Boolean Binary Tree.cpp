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
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    bool evaluateTree(TreeNode* root) {
        if (root == nullptr) return true;

        if (isLeaf(root)) {
            return root->val == 1 ? true : false;
        }

        bool leftEval = evaluateTree(root->left);
        bool rightEval = evaluateTree(root->right);

        if (root->val == 2) return leftEval || rightEval;
        return leftEval && rightEval;
    }
};