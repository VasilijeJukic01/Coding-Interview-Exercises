#include <array>

class Solution {
public:
    // {vertex, parent}
    using p = array<int, 2>;

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        queue<p> q;
        vector<bool> visited(n, false);

        // Acyclic check
        q.push({0, -1});
        visited[0] = true;
        while (!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            for (int k = 0; k < adjList[curr].size(); k++) {
                int neighbor = adjList[curr][k];
                if (visited[neighbor] && (parent != neighbor)) return false;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, curr});
                }
                
            }
        }

        // Component check
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) return false;
        }

        return true;
    }
};
