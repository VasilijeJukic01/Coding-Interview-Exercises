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
    int solve(TreeNode* root, int &best) {
        if (root == nullptr) return 0;

        int leftSum = solve(root->left, best);
        int rightSum = solve(root->right, best);

        int chain = root->val + leftSum + rightSum;
        int currBest = max(root->val, max(root->val + leftSum, root->val + rightSum));

        best = max(best, max(chain, currBest));

        return currBest;
    }

    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        solve(root, best);

        return best;
    }
};