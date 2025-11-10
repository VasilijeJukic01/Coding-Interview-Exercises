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

    void solve(TreeNode* root, int x, int y, int &xDepth, int &yDepth, int d, int &pX, int &pY, int p) {
        if (root == nullptr) return;

        solve(root->left, x, y, xDepth, yDepth, d+1, pX, pY, root->val);
        if (root->val == x) {
            xDepth = d;
            pX = p;
        }
        if (root->val == y) {
            yDepth = d;
            pY = p;
        }
        solve(root->right, x, y, xDepth, yDepth, d+1, pX, pY, root->val);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = 0, yDepth = 0;
        int pX = 0, pY = 0;

        solve(root, x, y, xDepth, yDepth, 0, pX, pY, -1);

        return xDepth == yDepth && pX != pY;
    }
};