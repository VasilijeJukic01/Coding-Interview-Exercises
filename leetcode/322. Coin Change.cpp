class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int w = 0; w <= amount; w++) {
                int dontInclude = dp[w];
                int include = INT_MAX - 1;
                if (w - coins[i] >= 0) {
                    include = 1 + dp[w - coins[i]];
                }

                dp[w] = min(dontInclude, include);
            }
        }

        if (dp[amount] == INT_MAX - 1) return -1;
        return dp[amount];
    }
};