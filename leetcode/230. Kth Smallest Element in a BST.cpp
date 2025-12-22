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
    void dfs(TreeNode* root, int k, int& counter, int& save) {
        if (root == nullptr || save != INT_MIN) return;

        dfs(root->left, k, counter, save);
        counter++;
        if (counter == k) save = root->val;
        dfs(root->right, k, counter, save);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = INT_MIN;
        int counter = 0;
        dfs(root, k, counter, result);

        return result;
    }
};