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

#define UNBALANCED -1

public:

    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = checkHeight(root->left);
        int rightH = checkHeight(root->right);

        if (leftH == UNBALANCED || rightH == UNBALANCED || abs(leftH - rightH) >= 2) {
            return -1;
        }

        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != UNBALANCED;
    }
};