class Node {
public:
    map<string, Node*> children;
    string folderName;
    bool marker;

    Node(string name) : folderName(name), marker(false) {}

    ~Node() {
        for (auto entry : children) {
            delete entry.second;
        }
    }
};

class Trie {
public:
    Node* root;
    // {serializedStructure, root}
    unordered_map<string, Node*> visited;

    Trie () {
        this->root = new Node("/");
    }

    void insert(vector<string> path) {
        Node* curr = root;
        for (int i = 0; i < path.size(); i++) {
            if (curr->children.count(path[i]) == 0) {
                curr->children[path[i]] = new Node(path[i]);
            }
            curr = curr->children[path[i]];
        }
    }

    // [/[a[b[x[y]]] c[b] w[y]]
    string serialize(Node* root) {
        string structure = "";
        for (auto& [folder, child] : root->children) {
            structure += serialize(child);
        }

        // [y] : x vs [y] : w
        if (!structure.empty()) {
            if (visited.count(structure)) {
            visited[structure]->marker = true;
            root->marker = true;
            }
            else visited[structure] = root;
        }

        return "[" + root->folderName + structure + "]";
    }

    void removeMarked(Node* root, vector<string> curr, vector<vector<string>>& save) {
        if (root->marker) return;

        if (root->folderName != "/") {
            curr.push_back(root->folderName);
            save.push_back(curr);
        }

        for (auto& [folder, child] : root->children) {
            removeMarked(child, curr, save);
        }

        if (root->folderName != "/") curr.pop_back();
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<vector<string>> result;
        Trie* trie = new Trie();

        for (int i = 0; i < paths.size(); i++) {
            trie->insert(paths[i]);
        }

        trie->serialize(trie->root);
        trie->removeMarked(trie->root, {}, result);

        return result;
    }
};