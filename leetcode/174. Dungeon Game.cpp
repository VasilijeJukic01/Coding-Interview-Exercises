class Solution {
public:
    using table = vector<vector<int>>;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        table dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                dp[i][j] = max(1, min(right, down) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};