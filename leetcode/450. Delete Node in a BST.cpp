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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        if (root->val == key) {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode* leftMax = findLeftMax(root->left);
                root->val = leftMax->val;
                root->left = deleteNode(root->left, leftMax->val);
            }
        }

        return root;
    }
};