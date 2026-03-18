class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, string& s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = 2 + solve(memo, s, i + 1, j - 1);
        }
        else {
            int moveI = solve(memo, s, i + 1, j);
            int moveJ = solve(memo, s, i, j - 1);
            return memo[i][j] = max(moveI, moveJ);
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        table memo(n, vector<int>(n, -1));
        return solve(memo, s, 0, n - 1);
    }
};