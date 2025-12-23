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
    int dfs(TreeNode* root, int &best) {
        if (root == nullptr) return 0;

        int leftResult = dfs(root->left, best);
        int rightResult = dfs(root->right, best);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left && root->val == root->left->val) {
            leftPath = leftResult + 1;
        }
        if (root->right && root->val == root->right->val) {
            rightPath = rightResult + 1;
        }

        best = max(best, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;

        int best = 0;
        dfs(root, best);

        return best;
    }
};