class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n + 1);
        vector<int> indeg(n + 1, 0);

        for (auto& p : relations) {
            int u = p[0];
            int v = p[1];
            adjList[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;
        int visited = 0;
        
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                visited++;
            }
        }

        int counter = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int curr = q.front();
                q.pop();

                for (auto& neighbor : adjList[curr]) {
                    indeg[neighbor]--;
                    if (indeg[neighbor] == 0) {
                        q.push(neighbor);
                        visited++;
                    }
                }
            }
            counter++;
        }

        if (visited < n) return -1;
        return counter;
    }
};
