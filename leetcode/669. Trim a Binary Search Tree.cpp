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
    TreeNode* findLeftMax(TreeNode* root) {
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }
        return curr;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        if (root->val < low || root->val > high) {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                return temp;
            }
            else {
                TreeNode* leftMax = findLeftMax(root->left);
                root->val = leftMax->val;
                root->left = trimBST(leftMax, low, high);
            }
        }

        return root;
    }
};