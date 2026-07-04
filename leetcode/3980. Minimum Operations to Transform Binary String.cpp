class Solution {
    using table = vector<vector<int>>;
public:
    int solve(table& memo, int i, char ch, string& s1, string& s2, int n) {
        if (i == n) return 0;

        if (memo[i][ch - '0'] != -1) {
            return memo[i][ch - '0'];
        }

        char next = (i + 1 < n) ? s1[i + 1] : '0';

        if (ch == s2[i]) {
            return memo[i][ch - '0'] = solve(memo, i + 1, next, s1, s2, n);
        }
        if (ch == '0') {
            return memo[i][ch - '0'] = 1 + solve(memo, i + 1, next, s1, s2, n);
        }

        int res = 1e9;
        if (i + 1 < n) {
            int cost = (s1[i + 1] == '1') ? 1 : 2;
            int nextCall = solve(memo, i + 1, '0', s1, s2, n);
            res = min(res, cost + nextCall);
        }
        if (n > 1) {
            int nextCall = solve(memo, i + 1, next, s1, s2, n);
            res = min(res, 2 + nextCall);
        }

        return memo[i][ch - '0'] = res;
    }
    
    int minOperations(string s1, string s2) {
        int n = s1.size();
        table memo(n, vector<int>(2, -1));

        int res = solve(memo, 0, s1[0], s1, s2, n);
        if (res == 1e9) return -1;
        return res;
    }
};