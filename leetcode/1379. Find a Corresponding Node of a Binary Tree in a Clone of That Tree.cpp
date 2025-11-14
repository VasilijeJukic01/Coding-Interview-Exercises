/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findTarget(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &result) {
        if (original == nullptr) return;
        if (cloned->val == target->val) {
            result = cloned;
            return;
        }
        findTarget(original->left, cloned->left, target, result);
        findTarget(original->right, cloned->right, target, result);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result = nullptr;
        findTarget(original, cloned, target, result);
        return result;
    }
};