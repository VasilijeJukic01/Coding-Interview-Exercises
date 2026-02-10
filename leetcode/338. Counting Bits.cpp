class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i / 2];
            if (i & 1) {
                dp[i] = dp[i / 2] + 1;
            }
            else dp[i] = dp[i / 2];
        }

        return dp;
    }
};