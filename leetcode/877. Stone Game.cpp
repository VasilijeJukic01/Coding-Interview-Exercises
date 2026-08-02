class Solution {
    using table = vector<vector<int>>;
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        table dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int takeLeft = piles[i] - dp[i + 1][j];
                int takeRight = piles[j] - dp[i][j - 1];
                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1];
    }
};