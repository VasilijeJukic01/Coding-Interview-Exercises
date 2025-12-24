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
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                ss << "N,";
                continue;
            }

            ss << node->val << ",";
            q.push(node->left);
            q.push(node->right);
        }

        string result = ss.str();

        while (result.size() >= 2 && result.substr(result.size() - 2) == "N,") {
            result.erase(result.size() - 2);
        }

        if (!result.empty() && result.back() == ',')
            result.pop_back();

        return result;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> tokens;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < tokens.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (tokens[i] != "N") {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < tokens.size() && tokens[i] != "N") {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));