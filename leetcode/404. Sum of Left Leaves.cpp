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
    
    void solve(TreeNode* root, int &sum, bool isRoot, int dir) {
        if (root == nullptr) return;

        if (!isRoot && root->left == nullptr && root->right == nullptr) {
            if (dir == -1) sum += root->val;
        }

        solve(root->left, sum, false, -1);
        solve(root->right, sum, false, 1);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root, sum, true, -1);
        return sum;
    }
};