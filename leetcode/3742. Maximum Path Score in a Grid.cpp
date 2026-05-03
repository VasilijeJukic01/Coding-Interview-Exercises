class Solution {
public:
    using table = vector<vector<vector<int>>>;

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        table dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 2, -1e9)));
        for (int w = 0; w <= k; w++) {
            if (grid[m - 1][n - 1] > 0 && w == 0) {
                continue;
            }
            dp[m - 1][n - 1][w] = grid[m - 1][n - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                for (int w = k; w >= 0; w--) {
                    int right, down;
                    if (grid[i][j] > 0) {
                        if (w == 0) dp[i][j][w] = -1e9;
                        else {
                            dp[i][j][w] = grid[i][j] + max(
                                dp[i][j + 1][w - 1], 
                                dp[i + 1][j][w - 1]
                            );
                        }
                    }
                    else {
                        dp[i][j][w] = grid[i][j] + max(
                            dp[i][j + 1][w], 
                            dp[i + 1][j][w]
                        );
                    }
                }
            }
        }
        
        return (dp[0][0][k] < 0) ? -1 : dp[0][0][k];
    }
};