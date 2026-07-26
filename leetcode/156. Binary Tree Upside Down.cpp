/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    using vv = vector<vector<TreeNode*>>;
public:
    void fillLevels(TreeNode* root, vv& levels, int h) {
        if (root == nullptr) return;

        if (h >= levels.size()) {
            levels.push_back({root});
        }
        else levels[h].push_back(root);

        fillLevels(root->left, levels, h + 1);
        fillLevels(root->right, levels, h + 1);
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        vv levels;
        fillLevels(root, levels, 0);

        TreeNode* mainRoot = levels.back()[0];
        TreeNode* curr = mainRoot;

        for (int i = levels.size() - 1; i >= 0; i--) {
            if (i != levels.size() - 1) {
                curr->right = levels[i][0];
                curr = curr->right;
            }

            TreeNode* lPointer = curr;
            lPointer->left = nullptr;
            lPointer->right = nullptr;
            for (int j = 1; j < levels[i].size(); j++) {
                lPointer->left = levels[i][j];
                
                lPointer = lPointer->left;
                lPointer->left = nullptr;
                lPointer->right = nullptr;
            }
        }

        return mainRoot;
    }
};
