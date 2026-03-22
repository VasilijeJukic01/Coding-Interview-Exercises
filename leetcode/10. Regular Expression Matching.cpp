class Solution {
public:
    using table = vector<vector<int>>;

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        table dp(m + 1, vector<int>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                }
                else dp[i][j] = match && dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};