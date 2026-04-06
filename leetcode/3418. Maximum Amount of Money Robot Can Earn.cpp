class Solution {
public:
    using grid = vector<vector<int>>;
    using table = vector<vector<vector<int>>>;

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        table dp(m + 1, grid(n + 1, vector<int>(3, -1e9)));

        for (int ability = 2; ability >= 0; ability--) {
            if (coins[m - 1][n - 1] < 0 && ability > 0) {
                dp[m - 1][n - 1][ability] = 0;
            }
            else dp[m - 1][n - 1][ability] = coins[m - 1][n - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                for (int ability = 2; ability >= 0; ability--) {
                    int dontUse = -1e9, use = -1e9;

                    int rightSame = dp[i][j + 1][ability];
                    int downSame = dp[i + 1][j][ability];
                    dontUse = coins[i][j] + max(rightSame, downSame);

                    if (coins[i][j] < 0 && ability > 0) {
                        int rightUse = dp[i][j + 1][ability - 1];
                        int downUse = dp[i + 1][j][ability - 1];
                        use = max(rightUse, downUse);
                    }

                    dp[i][j][ability] = max(use, dontUse);
                }
            }
        }

        return dp[0][0][2];
    }
};