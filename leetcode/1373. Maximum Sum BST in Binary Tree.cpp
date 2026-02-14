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
#define VALID 1
#define INVALID 0

class Solution {
public:
    // {accumulator, state, min, max}
    using t = array<int, 4>;

    t dfs(TreeNode* root, int& best) {
        if (root == nullptr) return {0, VALID, INT_MAX, INT_MIN};

        t lTree = dfs(root->left, best);
        t rTree = dfs(root->right, best);

        if (lTree[1] == VALID && rTree[1] == VALID) {
            if (root->val > lTree[3] && root->val < rTree[2]) {
                int sum = root->val + lTree[0] + rTree[0];
                best = max(best, sum);
                return {sum, VALID, min(lTree[2], root->val), max(rTree[3], root->val)};
            }
        }

        return {0, INVALID, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        int best = 0;
        dfs(root, best);
        return best;
    }
};