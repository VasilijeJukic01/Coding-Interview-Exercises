class Solution {
    const int dI[4] = {1, 0, -1, 0};
    const int dJ[4] = {0, 1, 0, -1};
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool isBorder(int i, int j, int m, int n) {
        return i == 0 || i == m - 1 || j == 0 || j == n - 1;
    }

    bool bfs(vector<vector<int>>& grid, int sI, int sJ) {
        int m = grid.size(), n = grid[0].size();

        queue<array<int, 2>> q;
        q.push({sI, sJ});
        grid[sI][sJ] = 1;

        bool closed = true;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + dI[k], nJ = j + dJ[k];
                if (!isSafe(nI, nJ, m, n) || grid[nI][nJ] == 1) continue;
                if (isBorder(nI, nJ, m, n)) closed = false;

                q.push({nI, nJ});
                grid[nI][nJ] = 1;
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int total = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    if (bfs(grid, i, j)) total++;
                }
            }
        }

        return total;
    }
};