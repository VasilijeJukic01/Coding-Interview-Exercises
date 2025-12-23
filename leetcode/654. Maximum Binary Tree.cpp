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
    pair<int, int> findMax(vector<int>& nums, int start, int end) {
        int best = nums[start];
        int index = start;
        for (int i = start; i <= end; i++) {
            if (nums[i] > best) {
                best = nums[i];
                index = i;
            }
        }

        return {best, index};
    }

    TreeNode* construct(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        pair<int, int> p = findMax(nums, start, end);

        TreeNode* root = new TreeNode(p.first);
        
        root->left = construct(nums, start, p.second - 1);
        root->right = construct(nums, p.second + 1, end);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};