/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        // {original, clone}
        unordered_map<Node*, Node*> map;
        
        queue<Node*> q;
        q.push(node);
        map[node] = new Node(node->val);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            for (int i = 0; i < node->neighbors.size(); i++) {
                Node* child = node->neighbors[i];
                if (map.count(child) == 0) {
                    map[child] = new Node(child->val);
                    q.push(child);
                }
                map[node]->neighbors.push_back(map[child]);
            }
        }

        return map[node];
    }
};