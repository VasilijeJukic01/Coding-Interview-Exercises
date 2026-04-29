class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    bool isSafe(int m, int n, int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool checkCycle(vector<vector<char>>& grid, int m, int n, int sI, int sJ, unordered_set<long long>& visited) {
        // {node, parent}
        unordered_map<long long, array<int, 2>> parent;
        queue<array<int, 2>> q;
        q.push({sI, sJ});
        
        long long sKey = ((long long)sI << 32) | sJ;
        visited.insert(sKey);
        parent[sKey] = {INT_MAX - 1, INT_MAX - 1};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + dy[k];
                int nJ = j + dx[k];
                if (!isSafe(m, n, nI, nJ)) continue;
                if (grid[i][j] != grid[nI][nJ]) continue;

                long long key = ((long long)nI << 32) | nJ;
                if (!parent.count(key)) {
                    q.push({nI, nJ});
                    visited.insert(key);
                    parent[key] = {i, j};
                }
                else {
                    long long currKey = ((long long)i << 32) | j;
                    if (parent[currKey][0] != nI || parent[currKey][1] != nJ) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<long long> visited;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long key = ((long long)i << 32) | j;
                if (visited.find(key) != visited.end()) continue;
                if (checkCycle(grid, m, n, i, j, visited)) return true;
            }
        }

        return false;
    }
};