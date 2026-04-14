class Solution {
public:
    using table = vector<vector<bool>>;

    bool checkValidString(string s) {
        int n = s.size();

        table dp(n + 1, vector<bool>(n / 2 + 1, false));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = n / 2; open >= 0; open--) {
                if (s[i] == '*') {
                    bool option1 = dp[i + 1][open];
                    bool option2 = false;
                    if (open < n / 2) {
                        option2 = dp[i + 1][open + 1];
                    }
                    bool option3 = false;
                    if (open > 0) {
                        option3 = dp[i + 1][open - 1];
                    }
                    dp[i][open] = option1 || option2 || option3;
                }

                else if (open < n / 2 && s[i] == '(') {
                    dp[i][open] = dp[i + 1][open + 1];
                }
                else if (open > 0 && s[i] == ')') {
                    dp[i][open] = dp[i + 1][open - 1];
                }
            }
        }

        return dp[0][0];
    }
};