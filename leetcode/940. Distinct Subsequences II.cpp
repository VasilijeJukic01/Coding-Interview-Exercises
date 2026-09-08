class Solution {
    using ll = long long;

    using table = vector<ll>;
    const int MOD = 1e9 + 7;
public:
    ll solve(table& memo, string& s, int i, vector<int>& prev) {
       if (i < 0) return 1;

       if (memo[i] != -1) return memo[i];

       ll exclude = solve(memo, s, i - 1, prev);
       ll include = solve(memo, s, i - 1, prev);

       int prevIdx = prev[i];
       if (prevIdx != -1) {
        ll sub = solve(memo, s, prevIdx - 1, prev);
        include = (include - sub + MOD) % MOD;
       }

       return memo[i] = include + exclude;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> last(26, -1);
        vector<int> prev(n, -1);
        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        table memo(n, -1);
        return (solve(memo, s, n - 1, prev) - 1 + MOD) % MOD;
    }
};