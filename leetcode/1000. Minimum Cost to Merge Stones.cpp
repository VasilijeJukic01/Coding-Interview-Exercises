class Solution {
public:
    using table = vector<vector<vector<int>>>;

    // Interval is [i, j]
    // m = how many piles we want in this range
    int solve(table& memo, vector<int>& pSum, int i, int j, int m, int k) {
        if (i == j) {
            if (m == 1) return 0;
            return 1e9;
        }

        if (memo[i][j][m] != -1) {
            return memo[i][j][m];
        }

        // If we want 1 pile and we are in interval -> divide
        if (m == 1) {
            int cost = pSum[j + 1] - pSum[i];
            return memo[i][j][m] = cost + solve(memo, pSum, i, j, k, k);
        }

        int minCost = 1e9;
        // [3 | 2  4  1]
        for (int mid = i; mid < j; mid += (k - 1)) {
            int leftPile = solve(memo, pSum, i, mid, 1, k);
            int rightPile = solve(memo, pSum, mid + 1, j, m - 1, k);
            minCost = min(minCost, leftPile + rightPile);
        }

        return memo[i][j][m] = minCost;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // n - m(k - 1) = 1
        // n - 1 = m(k - 1)
        if ((n - 1) % (k - 1) != 0) return -1;

        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + stones[i];
        }

        table memo(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(memo, pSum, 0, n - 1, 1, k);
    }
};