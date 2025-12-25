/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    void createGraph(TreeNode* root, TreeNode* parent) {
        if (root == nullptr) return;

        parents[root] = parent;

        createGraph(root->left, root);
        createGraph(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        createGraph(root, nullptr);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        while (!q.empty() && k > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                vector<TreeNode*> neighbors = {node->left, node->right, parents[node]};
                for (TreeNode* n : neighbors) {
                    if (n && visited.find(n) == visited.end()) {
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }

            k--;
        }

        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};