class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<array<int, 2>> q;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                grid[i][n - 1] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                grid[m - 1][j] = 0;
            }
        }

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + y[k];
                int nJ = j + x[k];
                if (isSafe(nI, nJ, m, n) && grid[nI][nJ] == 1) {
                    q.push({nI, nJ});
                    grid[nI][nJ] = 0;
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) counter++;
            }
        }

        return counter;
    }
};