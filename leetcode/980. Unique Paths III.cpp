class Solution {
public:
    using grid = vector<vector<int>>;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void solve(grid& g, int i, int j, int steps, int need, int& total) {
        if (steps < need && g[i][j] == 2) return;
        if (steps == need && g[i][j] == 2) {
            total++;
            return;
        }

        for (int k = 0; k < 4; k++) {
            int nI = i + dy[k];
            int nJ = j + dx[k];

            if (!isSafe(nI, nJ, g.size(), g[0].size())) continue;
            if (g[nI][nJ] == -1) continue;

            int save = g[i][j];
            g[i][j] = -1;
            solve(g, nI, nJ, steps + 1, need, total);
            // Backtrack
            g[i][j] = save;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int need = 0;
        int srcI, srcJ;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) need++;
                else if (grid[i][j] == 1) {
                    srcI = i;
                    srcJ = j;
                }
            }
        }

        int total = 0;
        solve(grid, srcI, srcJ, 0, need + 1, total);
        return total;
    }
};