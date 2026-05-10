class Solution {
public:
    // {jumps, isPossible}
    using p = array<long long, 2>;

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<p> dp(n, array<long long, 2>({LONG_MIN, LONG_MIN}));
        dp[n - 1] = {0, true};

        for (int i = n - 2; i >= 0; i--) {
            p total = {0, false};
            for (int k = i + 1; k < n; k++) {
                if (abs(nums[k] - nums[i]) <= target) {
                    // Jump to the end is possible
                    if (dp[k][1]) {
                        total = {max(total[0], 1 + dp[k][0]), total[1] || dp[k][1]};
                    }
                }
            }
            dp[i] = total;
        }

        if (dp[0][0] == 0 || dp[0][1] == false) return -1;
        return dp[0][0];
    }
};