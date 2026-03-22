class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int j = n - 1; j >= 0; j--) {
            if (p[j] == '*') {
                dp[m][j] = dp[m][j + 1];
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[j] == '*') {
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};