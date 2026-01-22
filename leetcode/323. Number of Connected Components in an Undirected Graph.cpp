class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = n;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                // BFS
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int k = 0; k < adjList[curr].size(); k++) {
                        if (visited[adjList[curr][k]] == false) {
                            q.push(adjList[curr][k]);
                            visited[adjList[curr][k]] = true;
                            components--;
                        }
                    } 
                }
            }
        }

        return components;
    }
};
