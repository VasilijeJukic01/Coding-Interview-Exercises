class Solution {
    using ll = long long;
public:
    ll maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();

        vector<ll> curr(5, -1e18);
        vector<ll> prev(5, -1e18);
        prev[0] = 0;
        curr[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 4; j++) {
                ll skip = prev[j];
                ll use = ((ll)a[j - 1] * b[i - 1]) + prev[j - 1];
                curr[j] = max(skip, use);
            }
            prev = curr;
        }

        return curr[4];
    }
};