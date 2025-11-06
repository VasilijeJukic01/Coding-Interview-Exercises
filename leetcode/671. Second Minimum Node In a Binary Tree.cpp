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

    void solve(TreeNode* root, int min, set<int> &bucket) {
        if (root == nullptr) return;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        if (left) {
            if (left->val != min) {
                bucket.insert(left->val);
                return;
            }
            else solve(root->left, min, bucket);
        }
        if (right) {
            if (right->val != min) {
                bucket.insert(right->val);
                return;
            }
            else solve(root->right, min, bucket);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> bucket;
        solve(root, root->val, bucket);

        long result = LONG_MAX;
        for (auto i : bucket) {
            result = i < result ? i : result;
        }

        return result == LONG_MAX ? -1 : result;
    }
};