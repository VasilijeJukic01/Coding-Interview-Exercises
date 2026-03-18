class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, string& s, string& t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        // Prunning
        int window = s.size() - t.size();
        if (abs(i - j) > window) return 0;

        int proceed = 0;
        int skip = solve(memo, s, t, i + 1, j);
        if (s[i] == t[j]) proceed = solve(memo, s, t, i + 1, j + 1);

        return memo[i][j] = skip + proceed;
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0;

        table memo(m, vector<int>(n, -1));
        return solve(memo, s, t, 0, 0);
    }
};