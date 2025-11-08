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

    int calculate(TreeNode* root, int &d) {
        if (root == nullptr) return 0;

        int leftH = calculate(root->left, d);
        int rightH = calculate(root->right, d);

        d = max(leftH + rightH, d);

        return max(leftH, rightH) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        calculate(root, d);
        return d;
    }
};