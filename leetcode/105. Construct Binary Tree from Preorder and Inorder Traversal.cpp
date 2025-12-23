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

    TreeNode* divideAndConquer(vector<int>& preorder, int start, int end, int &index) {
        if (start > end) return nullptr;

        int val = preorder[index];
        index++; 

        TreeNode* root = new TreeNode(val);
        int mid = indices[val];

        root->left = divideAndConquer(preorder, start, mid - 1, index);
        root->right = divideAndConquer(preorder, mid + 1, end, index);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }

        return divideAndConquer(preorder, 0, inorder.size() - 1, index);
    }
};