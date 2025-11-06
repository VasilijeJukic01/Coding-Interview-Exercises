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
    int binToInt(string bin) {
        int res = 0;
        for (int i = 0; i < bin.size(); i++) {
            res += (bin[i] - '0') * pow(2, bin.size() - 1 - i);
        }
        return res;
    }

    void sum(TreeNode* root, int &total, string curr) {
        if (root == nullptr) return;

        curr += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            total += binToInt(curr);
        }

        sum(root->left, total, curr);
        sum(root->right, total, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        sum(root, total, "");
        return total;
    }
};