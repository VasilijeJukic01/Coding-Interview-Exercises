class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int total = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (matrix[i][0]) {
                dp[i][0] = 1;
                total++;
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j]) {
                dp[0][j] = 1;
                total++;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) continue;

                if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    total += dp[i][j];
                }
            }
        }

        return total;
    }
};