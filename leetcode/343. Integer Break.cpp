class Solution {
public:
    int solve(vector<int>& memo, int n) {
        if (n == 1) return 1;

        if (memo[n] != -1) return memo[n];

        int best = 0;
        for (int i = 1; i < n; i++) {
            int optionA = i * (n - i);
            int optionB = i * solve(memo, n - i);
            best = max(best, max(optionA, optionB));
        }

        return memo[n] = best;
    }

    int integerBreak(int n) {
        vector<int> memo(n + 1, -1);

        return solve(memo, n);
    }
};