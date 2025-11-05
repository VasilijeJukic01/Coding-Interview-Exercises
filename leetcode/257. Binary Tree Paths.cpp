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

    string concat(string x, string y) {
        stringstream stream;
        if (x.empty()) stream << y;
        else stream << x << "->" << y;
        return stream.str();
    }

    void findPaths(TreeNode* root, vector<string> &p, string curr) {
        if (root == nullptr) return;

        curr = concat(curr, to_string(root->val));
        if (root->left == nullptr && root->right == nullptr) {
            p.push_back(curr);
        }
        findPaths(root->left, p, curr);
        findPaths(root->right, p, curr);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> p;
        findPaths(root, p, "");
        return p;
    }
};