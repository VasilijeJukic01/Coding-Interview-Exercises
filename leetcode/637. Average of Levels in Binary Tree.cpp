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

    void solve(TreeNode* root, vector<pair<double, double>> &v, int lvl) {
        if (root == nullptr) return;
        if (lvl >= v.size()) {
            v.push_back({root->val, 1});
        }
        else {
            v[lvl].first += root->val;
            v[lvl].second++;
        }
        solve(root->left, v, lvl+1);
        solve(root->right, v, lvl+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<pair<double, double>> v;

        solve(root, v, 0);

        for (int i = 0; i < v.size(); i++) {
            result.push_back(v[i].first / v[i].second);
        }

        return result;
    }
};