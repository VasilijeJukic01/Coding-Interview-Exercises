/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        Node* leftChild = connect(root->left);
        Node* rightChild = connect(root->right);

        if (leftChild && rightChild) {
            leftChild->next = rightChild;
            Node* lr = leftChild->right;
            Node* rl = rightChild->left;
            while (lr && rl) {
                lr->next = rl;
                lr = lr->right;
                rl = rl->left;
            }
        }

        return root;
    }
};