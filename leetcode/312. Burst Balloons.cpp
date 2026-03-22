class Solution {
public:
    using table = vector<vector<int>>;

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int m = n + 2;

        vector<int> balloons(m, 1);
        for (int i = 1; i < m - 1; i++) {
            balloons[i] = nums[i - 1];
        }

        table dp(m, vector<int>(m, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j < m; j++) {
                for (int k = i + 1; k < j; k++) {
                    int coins = balloons[i] * balloons[k] * balloons[j];
                    dp[i][j] = max(dp[i][j], coins + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][m - 1];
    }
};