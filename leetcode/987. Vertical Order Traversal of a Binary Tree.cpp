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
    // {val, row, col}
    typedef struct triple {
        int x;
        int y;
        int z;
    } triple;

    void fillNodes(TreeNode* root, int row, int col, vector<triple>& nodes) {
        if (root == nullptr) return;

        nodes.push_back({root->val, row, col});

        fillNodes(root->left, row + 1, col - 1, nodes);
        fillNodes(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        vector<triple> nodes;

        fillNodes(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end(), [](const triple& t1, const triple& t2) {
            bool firstCheck = t1.z < t2.z;
            bool secondCheck = t1.z == t2.z && t1.y < t2.y;
            bool thirdCheck = t1.z == t2.z && t1.y == t2.y && t1.x < t2.x;
            return firstCheck || secondCheck || thirdCheck;
        });

        v.push_back({nodes[0].x});
        int vIndex = 0;
        for (int i = 1; i < nodes.size(); i++) {
            if (nodes[i - 1].z == nodes[i].z) {
                v[vIndex].push_back(nodes[i].x);
            }
            else {
                v.push_back({nodes[i].x});
                vIndex++;
            }
        }

        return v;
    }
};