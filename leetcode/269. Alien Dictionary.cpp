class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adjList;
        unordered_map<char, int> indeg;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                adjList[words[i][j]] = {};
                indeg[words[i][j]] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool inserted = false;
            for (int k = 0; k < len; k++) {
                if (w1[k] != w2[k]) {
                    inserted = true;
                    if (adjList[w1[k]].find(w2[k]) != adjList[w1[k]].end()) {
                        break;
                    }
                    adjList[w1[k]].insert(w2[k]);
                    indeg[w2[k]]++;
                    break;
                }
            }
            if (!inserted && w1.size() > w2.size()) return "";
        }

        queue<char> q;
        for (auto& [node, _] : adjList) {
            if (indeg[node] == 0) q.push(node);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            result += curr;
            q.pop();

            for (auto& neighbor : adjList[curr]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != adjList.size()) return "";
        return result;
    }
};
