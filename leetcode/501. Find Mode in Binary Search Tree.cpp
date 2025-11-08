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

    void findMode(TreeNode* root, vector<int> &v, int &best, int &curr, int &value) {
        if (root == nullptr) return;

        findMode(root->left, v, best, curr, value);

        if (root->val == value) curr++;
        else {
            curr = 1;
            value = root->val;
        }

        if (curr > best) {
            best = curr;
            v.clear();
            v.push_back(root->val);
        }
        else if (curr == best) v.push_back(root->val);

        findMode(root->right, v, best, curr, value);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> mode;
        int best = 0, curr = 0;
        int value = INT_MIN;

        findMode(root, mode, best, curr, value);

        return mode;
    }
};