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

    void dfs(TreeNode* root, int &minD, int &predecessor) {
        if (root == nullptr) return;

        dfs(root->left, minD, predecessor);
        if (predecessor != -1) {
            minD = min(minD, abs(root->val - predecessor));
        }
        predecessor = root->val;
        dfs(root->right, minD, predecessor);
    }

    int minDiffInBST(TreeNode* root) {
        int minD = INT_MAX;
        int predecessor = -1;
        dfs(root, minD, predecessor);

        return minD;
    }
};