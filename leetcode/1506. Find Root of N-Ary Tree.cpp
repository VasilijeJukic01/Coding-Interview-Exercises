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
    Node* findRoot(vector<Node*> tree) {
        long long sum = 0;
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i]) sum += tree[i]->val;
        }

        for (int i = 0; i < tree.size(); i++) {
            if (tree[i]) {
                for (int j = 0; j < tree[i]->children.size(); j++) {
                    sum -= tree[i]->children[j]->val;
                }
            }
        }

        for (int i = 0; i < tree.size(); i++) {
            if (tree[i] && tree[i]->val == sum) return tree[i];
        }
    }
};
