class Solution {
    const int dI[4] = {1, 0, -1, 0};
    const int dJ[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int bfs(vector<vector<int>>& grid, int sI, int sJ, int k) {
        int m = grid.size(), n = grid[0].size();
        long long sum = grid[sI][sJ];

        queue<array<int, 2>> q;
        q.push({sI, sJ});
        grid[sI][sJ] = 0;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int p = 0; p < 4; p++) {
                int nI = i + dI[p], nJ = j + dJ[p];
                if (!isSafe(nI, nJ, m, n) || grid[nI][nJ] == 0) continue;

                sum += grid[nI][nJ];
                q.push({nI, nJ});
                grid[nI][nJ] = 0;
            }
        }

        if (sum % k == 0) return 1;
        return 0;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    total += bfs(grid, i, j, k);
                }
            }
        }

        return total;
    }
};