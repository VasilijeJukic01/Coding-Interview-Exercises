class Solution {
    using ll = long long;
    using table = vector<vector<ll>>;
public:
    ll solve(table& memo, vector<int>& nums, int k, int i, int prev, int r) {
        if (i == nums.size()) return 0;

        if (memo[i][prev] != -1) return memo[i][prev];

        ll skip = 0;
        if (prev == k) skip = solve(memo, nums, k, i + 1, k, r);

        ll curr = 1;
        if (prev == k) curr = nums[i];
        else curr = (prev * nums[i]) % k;

        ll take = (curr == r);
        take += solve(memo, nums, k, i + 1, curr, r);

        return memo[i][prev] = skip + take;
    }

    vector<ll> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> result(k, 0);
        for (int i = 0; i < n; i++) {
            nums[i] %= k;
        }

        for (int r = 0; r < k; r++) {
            table memo(n, vector<ll>(k + 1, -1));
            result[r] = solve(memo, nums, k, 0, k, r);
        }

        return result;
    }
};