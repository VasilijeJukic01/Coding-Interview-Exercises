class Solution {
public:
    using table = vector<vector<bool>>;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size();
        int n = s2.size();
        table dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m - 1; i >= 0; i--) {
            dp[i][n] = (s1[i] == s3[i + n]) && dp[i + 1][n];
        }

        for (int j = n - 1; j >= 0; j--) {
            dp[m][j] = (s2[j] == s3[m + j]) && dp[m][j + 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int k = i + j;

                bool optionA = false;
                bool optionB = false;
                if (s1[i] == s3[k]) optionA = dp[i + 1][j];
                if (s2[j] == s3[k]) optionB = dp[i][j + 1];

                dp[i][j] = optionA || optionB;
            }
        }

        return dp[0][0];
    }
};