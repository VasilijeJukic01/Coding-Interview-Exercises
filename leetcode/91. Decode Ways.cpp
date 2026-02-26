class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1; 

        for (int i = 1; i < n; i++) {
            // Decode as single digit
            if (s[i] != '0') dp[i] += dp[i-1];

            // Decode as two digits
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) {
                if (i == 1) dp[i] += 1; 
                else dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
};