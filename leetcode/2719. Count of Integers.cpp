class Solution {
    const int MOD = 1e9 + 7;
    using table = vector<vector<vector<vector<int>>>>;
public:
    int solve(table &memo, string &num, int i, bool tight, bool leadZero, int sum, int a, int b) {
        if (i == num.size()) {
            if (sum >= a && sum <= b) return 1;
            return 0;
        }

        if (memo[i][tight][leadZero][sum] != -1) {
            return memo[i][tight][leadZero][sum];
        }

        int total = 0;

        int lb = 0;
        int ub = tight ? num[i] - '0' : 9;
        for (int k = lb; k <= ub; k++) {
            bool tightP = (tight && (k == ub));
            bool leadZeroP = (leadZero && (k == 0));
            int sumP = sum + k;

            int res = solve(memo, num, i + 1, tightP, leadZeroP, sumP, a, b);
            total = (total + res) % MOD;
        }

        return memo[i][tight][leadZero][sum] = total;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num2.size();

        // [n] x [2] x [2] x [200]
        table memo(n, vector<vector<vector<int>>>(
            2, vector<vector<int>>(2, vector<int>(200, -1))
        ));
        table memo2(n, vector<vector<vector<int>>>(
            2, vector<vector<int>>(2, vector<int>(200, -1))
        ));
        int upper = solve(memo, num2, 0, true, true, 0, min_sum, max_sum);
        int lower = solve(memo2, num1, 0, true, true, 0, min_sum, max_sum);

        int num1Sum = 0;
        for (int i = 0; i < num1.size(); i++) {
            num1Sum += num1[i] - '0';
        }

        int remainder = (num1Sum >= min_sum && num1Sum <= max_sum) ? 1 : 0;
        return (upper - lower + remainder + MOD) % MOD;
    }
};