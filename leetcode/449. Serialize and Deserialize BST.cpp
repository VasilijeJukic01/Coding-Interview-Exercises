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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                ss << "N,";
                continue;
            }

            ss << curr->val << ',';
            q.push(curr->left);
            q.push(curr->right);
        }

        string result = ss.str();
        while (result.back() == 'N' || result.back() == ',') {
            result.pop_back();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> parts;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            parts.push_back(node);
        }

        int rootVal = stoi(parts[0]);
        int index = 1;
        TreeNode* root = new TreeNode(rootVal);

        queue<TreeNode*> q;
        q.push(root);
        while (index < parts.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left
            string leftChild = parts[index++];
            if (leftChild == "N") curr->left = nullptr;
            else {
                curr->left = new TreeNode(stoi(leftChild));
                q.push(curr->left);
            }
            // Right
            if (index < parts.size()) {
                string rightChild = parts[index++];
                if (rightChild == "N") curr->right = nullptr;
                else {
                    curr->right = new TreeNode(stoi(rightChild));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;