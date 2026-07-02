class Solution {
    using table = vector<vector<vector<vector<int>>>>;
public:
    int solve(table& memo, string& num, int i, bool tight, bool leadZero, int mask) {
        if (i == num.size()) return 1;

        if (memo[i][tight][leadZero][mask] != -1) {
            return memo[i][tight][leadZero][mask];
        }

        int total = 0;
        int ub = tight ? num[i] - '0' : 9;
        for (int k = 0; k <= ub; k++) {
            bool tightP = (tight && (k == ub));
            bool leadZeroP = (leadZero && (k == 0));
            if (!leadZeroP && (mask & (1 << k))) continue;

            int maskP = leadZeroP ? mask : (mask | (1 << k));
            total += solve(memo, num, i + 1, tightP, leadZeroP, maskP);
        }

        return memo[i][tight][leadZero][mask] = total;
    }

    int numDupDigitsAtMostN(int n) {
        string num = to_string(n);

        int len = num.size();
        // [len] x [2] x [2] x [1024]
        table memo(len, vector<vector<vector<int>>>(
            2, vector<vector<int>>(2, vector<int>(1024, -1))
        ));
        return n - solve(memo, num, 0, true, true, 0) + 1;
    }
};