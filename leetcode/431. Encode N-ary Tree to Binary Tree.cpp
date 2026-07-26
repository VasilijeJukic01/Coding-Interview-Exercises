/**
 * Definition for undirected graph.
 * struct Node {
 *     int label;
 *     vector<Node *> neighbors;
 *     Node(int x) : label(x) {};
 * }; * Definition of TreeNode:
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
public:
    /**
     * @param root: binary tree
     * @return: N-ary tree
     */
    Node* decode(TreeNode * root) {
        if (root == nullptr) return nullptr;
        Node* nRoot = new Node(root->val);

        TreeNode* curr = root->left;
        while (curr) {
            nRoot->neighbors.push_back(decode(curr));
            curr = curr->right;
        }

        return nRoot
    }

    /**
     * @param root: N-ary tree
     * @return: binary tree
     */
    TreeNode * encode(Node* root) {
        if (root == nullptr) return nullptr;
        TreeNode* bRoot = new TreeNode(root->val);

        TreeNode* curr = bRoot;
        for (int i = 0; i < root->neighbors.size(); i++) {
            Node* child = root->neighbors[i];
            if (i == 0) {
                curr->left = encode(child);
                curr = curr->left;
            }
            else {
                curr->right = encode(child);
                curr = curr->right;
            }
        }

        return bRoot;
    }
};