class Solution {
public:
    using p = array<int, 2>;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    void bfs(vector<vector<int>>& grid, int sI, int sJ, vector<vector<p>>& data, int id) {
        int n = grid.size();

        queue<p> q;
        vector<p> s;

        q.push({sI, sJ});
        s.push_back({sI, sJ});
        grid[sI][sJ] = -1;

        int surface = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + y[k];
                int nJ = j + x[k];

                if (isSafe(nI, nJ, n) && grid[nI][nJ] == 1) {
                    q.push({nI, nJ});
                    s.push_back({nI, nJ});
                    grid[nI][nJ] = -1;
                }
            }

            surface++;
        }

        for (auto& [i, j] : s) {
            data[i][j] = {id, surface};
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<p>> data(n, vector<p>(n, {0, 0}));
        // Collect data
        int id = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && data[i][j][0] == 0) {
                    bfs(grid, i, j, data, id);
                    id++;
                }
            }
        }

        // Find best candidate
        int maxSurface = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int total = 0;
                    unordered_set<int> ids;
                    int id;

                    for (int k = 0; k < 4; k++) {
                        int nI = i + y[k];
                        int nJ = j + x[k];
                        if (isSafe(nI, nJ, n)) {
                            id = data[nI][nJ][0];
                            if (id != 0 && (ids.find(id) == ids.end())){
                                ids.insert(id);
                                total += data[nI][nJ][1];
                            }

                        }
                    }

                    maxSurface = max(maxSurface, total + 1);
                }
            }
        }

        if (maxSurface == -1) return n * n;
        return maxSurface;
    }
};