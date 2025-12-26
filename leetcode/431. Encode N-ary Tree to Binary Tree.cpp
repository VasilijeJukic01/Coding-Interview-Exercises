/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    TreeNode* encode(Node* root) {
       if (root == nullptr) return nullptr;

        TreeNode* btRoot = new TreeNode(root->val);
        if (!root->children.empty()) {
            btRoot->left = new TreeNode(root->children[0]->val);
        }

        TreeNode* cur = btRoot->left;
        for (int i = 1; i < root->children.size(); ++i) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }

        return btRoot;
    }

    Node* decode(TreeNode* root) {
        if (root == nullptr) return nullptr;

        Node* node = new Node(root->val);

        TreeNode* cur = root->left;
        while (cur != nullptr) {
            node->children.push_back(decode(cur));
            cur = cur->right;
        }

        return node;
    }
};