class Solution {
public:

    int countCh(string s, char ch) {
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) total++;
        }
        return total;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (string s : strs) {
            int mCost = countCh(s, '0');
            int nCost = countCh(s, '1');
            for (int i = n; i >= nCost; i--) {
                for (int j = m; j >= mCost; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - nCost][j - mCost]);
                }
            }
        }

        return dp[n][m];
    }
};