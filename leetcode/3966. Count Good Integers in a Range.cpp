class Solution {
    using ll = long long;
    using table = vector<vector<vector<vector<ll>>>>;
public:
    ll solve(table &memo, string &num, int i, bool tight, bool leadZero, int prev, int k) {
        if (i == num.size()) return 1;

        if (memo[i][tight][leadZero][prev] != -1) {
            return memo[i][tight][leadZero][prev];
        }

        ll total = 0;
        int lb = 0;
        int ub = tight ? num[i] - '0' : 9;
        for (int j = lb; j <= ub; j++) {
            if (!leadZero && abs(prev - j) > k) continue;
            bool tightP = (tight && (j == ub));
            bool leadZeroP = (leadZero && (j == 0));

            total += solve(memo, num, i + 1, tightP, leadZeroP, j, k);
        }

        return memo[i][tight][leadZero][prev] = total;
    }

    ll goodIntegers(ll l, ll r, int k) {
        string num1 = to_string(l - 1);
        string num2 = to_string(r);

        int n = num2.size();
        int m = num1.size();
        // [n] x [2] x [2] x [10]
        table memo1(n, vector<vector<vector<ll>>>(
            2, vector<vector<ll>>(2, vector<ll>(10, -1))
        ));
        table memo2(m, vector<vector<vector<ll>>>(
            2, vector<vector<ll>>(2, vector<ll>(10, -1))
        ));

        ll upper = solve(memo1, num2, 0, true, true, 0, k);
        ll lower = solve(memo2, num1, 0, true, true, 0, k);

        return upper - lower;
    }
};