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

    void checkDepth(TreeNode* root, int &minD, int h) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            minD = h < minD ? h : minD;
        }
        checkDepth(root->left, minD, h+1);
        checkDepth(root->right, minD, h+1);
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int minD = INT_MAX;
        checkDepth(root, minD, 1);
        return minD;
    }
};