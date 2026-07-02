class Solution {
    using matrix = vector<vector<int>>;
    using table = vector<vector<vector<int>>>;

    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool solve(table& memo, matrix& grid, int i, int j, int h, int m, int n) {
        if (i == m - 1 && j == n - 1) return true;

        if (memo[i][j][h] != -1) {
            return memo[i][j][h];
        }

        int val = grid[i][j];
        grid[i][j] = 2;

        bool result = false;
        for (int k = 0; k < 4; k++) {
            int nI = i + dy[k];
            int nJ = j + dx[k];

            if (!isSafe(nI, nJ, m, n) || grid[nI][nJ] == 2) continue;

            if (grid[nI][nJ] == 0) {
                result = result || solve(memo, grid, nI, nJ, h, m, n);
            }
            else {
                if (h > 1) {
                    result = result || solve(memo, grid, nI, nJ, h - 1, m, n);
                }
            }
        }

        grid[i][j] = val;

        return memo[i][j][h] = result;
    }

    bool findSafeWalk(matrix& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        health -= grid[0][0]; 
        if (health <= 0) return false;

        table memo(m, matrix(n, vector<int>(health + 1, -1)));
        return solve(memo, grid, 0, 0, health, m, n);
    }
};