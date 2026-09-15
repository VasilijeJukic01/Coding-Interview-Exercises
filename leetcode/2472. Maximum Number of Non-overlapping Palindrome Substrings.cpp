class Solution {
    using vv = vector<vector<bool>>;
    using table = vector<vector<int>>;
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vv pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j - i < 2) pal[i][j] = (s[i] == s[j]);
                else {
                    pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
                }
            }
        }

        table dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Skip
                int skip = dp[j + 1][j + 1];
                // Use
                int use = dp[i][j + 1];
                // Build
                int build = 0;
                if (j - i + 1 >= k && pal[i][j]) {
                    build = 1 + dp[j + 1][j + 1];
                }

                dp[i][j] = max(skip, max(use, build));
            }
        }

        return dp[0][0];
    }
};