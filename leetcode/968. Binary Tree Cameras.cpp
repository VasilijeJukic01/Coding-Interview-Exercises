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

#define NOT_COVERED 0
#define COVERED 1
#define HAS_CAMERA 2

class Solution {
public:
    int placeCam(TreeNode* root, int& total) {
        if (root == nullptr) return COVERED;

        int leftState = placeCam(root->left, total);
        int rightState = placeCam(root->right, total);

        if (leftState == COVERED && rightState == COVERED) return NOT_COVERED;
        if (leftState == NOT_COVERED || rightState == NOT_COVERED) {
            total++;
            return HAS_CAMERA;
        }
        return COVERED;
    }

    int minCameraCover(TreeNode* root) {
        int total = 0;
        if (placeCam(root, total) == NOT_COVERED) total++;

        return total;
    }
};