class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int bfs(vector<vector<int>>& grid, int startI, int startJ) {
        int m = grid.size();
        int n = grid[0].size();

        int surface = 0;
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        queue<array<int, 2>> q;
        q.push({startI, startJ});
        grid[startI][startJ] = 0;

        while (!q.empty()) {
            array<int, 2> curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];

            for (int k = 0; k < 4; k++) {
                int nI = i + y[k];
                int nJ = j + x[k];
                if (isSafe(nI, nJ, m, n) && grid[nI][nJ] == 1) {
                    q.push({nI, nJ});
                    grid[nI][nJ] = 0;
                }
            }

            surface++;
        }

        return surface;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSurface = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int surface = bfs(grid, i, j);
                    maxSurface = max(maxSurface, surface);
                }
            }
        }

        return maxSurface;
    }
};