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
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};

        vector<int> v;
        // {Node, Visited}
        stack<pair<Node*, bool>> s;
        s.push({root, false});

        while (!s.empty()) {
            pair<Node*, bool> node = s.top();
            s.pop();
            
            if (node.second == true) {
                v.push_back(node.first->val);
            }
            else {
                s.push({node.first, true});
                for (int i = node.first->children.size() - 1; i >= 0; i--) {
                    s.push({node.first->children[i], false});
                }
            }
        }

        return v;
    }
};