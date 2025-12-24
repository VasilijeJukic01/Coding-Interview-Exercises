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
    int dfs(TreeNode* root, unordered_map<int, int> &sums) {
        if (root == nullptr) return 0;

        int leftSum = dfs(root->left, sums);
        int rightSum = dfs(root->right, sums);

        int sum = leftSum + rightSum + root->val;
        sums[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sums;

        dfs(root, sums);

        int maxFq = 0;
        vector<int> result;
        for (auto entry : sums) {
            if (entry.second == maxFq) result.push_back(entry.first);
            if (entry.second > maxFq) {
                result.clear();
                maxFq = entry.second;
                result.push_back(entry.first);
            }
        }

        return result;
    }
};