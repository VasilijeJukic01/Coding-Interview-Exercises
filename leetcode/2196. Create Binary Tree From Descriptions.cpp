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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // {value, treenode}
        unordered_map<int, TreeNode*> map;
        // {node, parent}
        unordered_map<int, int> parentMap;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;

            if (!map.count(parent)) {
                map[parent] = new TreeNode(parent);
            }
            if (!map.count(child)) {
                map[child] = new TreeNode(child);
            }

            if (isLeft) map[parent]->left = map[child];
            else map[parent]->right = map[child];

            parentMap[child] = parent;
        }

        for (auto& desc : descriptions) {
            if (parentMap[desc[0]] == 0) {
                return map[desc[0]];
            }
        }

        return nullptr;
    }
};