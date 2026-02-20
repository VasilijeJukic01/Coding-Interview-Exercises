class Solution {
public:
    vector<vector<string>> result;
    vector<vector<bool>> dp;

    void solve(string& s, int index, vector<string>& curr) {
        if (index == s.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!dp[index][i]) continue;

            curr.push_back(s.substr(index, i - index + 1));
            solve(s, i + 1, curr);
            // Backtrack
            curr.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (len == 1) dp[i][j] = true;
                else if (len == 2) dp[i][j] = (s[i] == s[j]);
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        vector<string> curr;
        solve(s, 0, curr);
        return result;
    }
};