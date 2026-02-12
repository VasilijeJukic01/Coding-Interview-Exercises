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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) return nullptr;

        TreeNode* tRoot = new TreeNode(root->val);
        if (!root->children.empty()) {
            tRoot->left = encode(root->children[0]);
        }

        TreeNode* curr = tRoot->left;
        for (int i = 1; i < root->children.size(); i++) {
            curr->right = encode(root->children[i]);
            curr = curr->right;
        }
        
        return tRoot;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) return nullptr;

        Node* nRoot = new Node(root->val);
        
        TreeNode* curr = root->left;
        while (curr) {
            nRoot->children.push_back(decode(curr));
            curr = curr->right;
        }

        return nRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
