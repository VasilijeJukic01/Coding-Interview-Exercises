#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorder(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;

    while (curr) {
        if (curr->left == nullptr) {
            // Case 1: No left child, visit this node and move right
            result.push_back(curr->val);
            curr = curr->right;
        }
        else {
            // Case 2: Left child exists, find the inorder predecessor
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                // Create a temporary thread to the current node
                prev->right = curr;
                curr = curr->left;
            }
            else {
                // Thread already exists, we finished the left subtree
                // Restore the tree
                prev->right = nullptr;
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    
    return result;
}