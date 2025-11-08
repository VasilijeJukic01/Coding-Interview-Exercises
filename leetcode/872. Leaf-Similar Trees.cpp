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

    void solve(TreeNode* root, vector<int> &map) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            map.push_back(root->val);
        }

        solve(root->left, map);
        solve(root->right, map);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> map1;
        vector<int> map2;
        solve(root1, map1);
        solve(root2, map2);

        if (map1.size() != map2.size()) return false;

        for (int i = 0; i < map1.size(); i++) {
            if (map1[i] != map2[i]) return false;
        }
        return true;
    }
};