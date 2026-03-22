class Solution {
public:
    using table = vector<vector<bool>>;

    int minCut(string s) {
        int n = s.size();

        table pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, n);
        dp[n] = -1;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = i; k < n; k++) {
                if (pal[i][k]) {
                    dp[i] = min(dp[i], 1 + dp[k + 1]);
                }
            }
        }

        return dp[0];
    }
};