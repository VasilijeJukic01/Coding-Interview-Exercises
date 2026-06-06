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
    void pathSum(TreeNode* root, int target, long long curr, unordered_map<long long, int> &map, int &total) {
        if (root == nullptr) return;

        curr += root->val;
        if (map.count(curr - target)) {
            total += map[curr - target];
        }
        map[curr]++;

        pathSum(root->left, target, curr, map, total);
        pathSum(root->right, target, curr, map, total);

        // Backtrack
        map[curr]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // {sum, occurence}
        unordered_map<long long, int> map;
        map[0] = 1;

        int total = 0;
        pathSum(root, targetSum, 0, map, total);
        return total;
    }
};