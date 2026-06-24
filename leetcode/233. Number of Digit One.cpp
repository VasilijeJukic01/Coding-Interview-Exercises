class Solution {
    using table = vector<vector<vector<vector<int>>>>;
public:
    int solve(table &memo, string &a, int i, bool tight, bool leadZeros, int ones) {
        if (i == a.size()) return ones;

        if (memo[i][tight][leadZeros][ones] != -1) {
            return memo[i][tight][leadZeros][ones];
        }

        int lb = 0;
        int ub = tight ? a[i] - '0' : 9;
        int total = 0;
        for (int k = lb; k <= ub; k++) {
            bool tightP = (tight && (k == ub));
            bool leadZerosP = (leadZeros && (k == 0));
            int onesP = ones + (k == 1 ? 1 : 0);

            total += solve(memo, a, i + 1, tightP, leadZerosP, onesP);
        }

        return memo[i][tight][leadZeros][ones] = total;
    }

    int countDigitOne(int n) {
        string a = to_string(n);

        int d = a.size();
        // [d] x [2] x [2] x [10]
        table memo(d, vector<vector<vector<int>>>(
            2, vector<vector<int>>(2, vector<int>(10, -1)))
        );
        return solve(memo, a, 0, true, true, 0);
    }
};