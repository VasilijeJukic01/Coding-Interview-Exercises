class Solution {
    using table = vector<vector<int>>;
public:
    int solve(table& memo, vector<int>& suff, int i, int m) {
        if (i >= suff.size() - 1) return 0;

        if (memo[i][m] != -1) return memo[i][m];

        int best = 0;
        for (int x = 1; x <= 2 * m; x++) {
            if (i + x >= suff.size()) break;
            int nextM = max(m, x);
            // Stones left - Bob's result
            int stones = suff[i] - solve(memo, suff, i + x, nextM);
            best = max(best, stones);
        }

        return memo[i][m] = best;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suff(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + piles[i];
        }

        table memo(n + 1, vector<int>(2 * n, -1));
        return solve(memo, suff, 0, 1);
    }
};