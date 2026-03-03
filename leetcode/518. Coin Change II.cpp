class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int c = coins[i]; c <= amount; c++) {
                dp[c] = dp[c] + dp[c - coins[i]];
            }
        }

        return dp[amount];
    }
};