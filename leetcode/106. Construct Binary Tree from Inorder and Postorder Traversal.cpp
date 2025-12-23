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
    unordered_map<int, int> indices;

    TreeNode* divideAndConquer(vector<int>& postorder, int start, int end, int &index) {
        if (start > end) return nullptr;

        int val = postorder[index];
        index--;

        TreeNode* root = new TreeNode(val);
        int mid = indices[val];

        root->right = divideAndConquer(postorder, mid + 1, end, index);
        root->left = divideAndConquer(postorder, start, mid - 1, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        for (int i = 0; i < postorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        return divideAndConquer(postorder, 0, postorder.size() - 1, index);
    }
};