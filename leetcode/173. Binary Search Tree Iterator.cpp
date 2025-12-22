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
class BSTIterator {
public:
    vector<int> iterator;
    int p = 0;

    BSTIterator(TreeNode* root) {
        init(root);
    }

    void init(TreeNode* root) {
        if (root == nullptr) return;

        init(root->left);
        iterator.push_back(root->val);
        init(root->right);
    }
    
    int next() {
        return iterator[p++];
    }
    
    bool hasNext() {
        return p < iterator.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */