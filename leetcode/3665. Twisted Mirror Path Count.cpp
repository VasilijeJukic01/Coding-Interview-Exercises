class Solution {
    const int DOWN = 0;
    const int RIGHT = 1;
    const int MOD = 1e9 + 7;
    using table = vector<vector<vector<int>>>;
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        table dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        dp[m - 1][n - 1][0] = 1;
        dp[m - 1][n - 1][1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                for (int prevDir = 0; prevDir <= 1; prevDir++) {
                    if (grid[i][j] == 0) {
                        int down = dp[i + 1][j][DOWN];
                        int right = dp[i][j + 1][RIGHT];
                        dp[i][j][prevDir] = (down + right) % MOD;
                    }
                    else {
                        if (prevDir == DOWN) {
                            dp[i][j][prevDir] = dp[i][j + 1][RIGHT];
                        }
                        else dp[i][j][prevDir] = dp[i + 1][j][DOWN];
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};