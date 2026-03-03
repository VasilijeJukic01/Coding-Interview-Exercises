class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, vector<int>& nums, int need, int index) {
        if (need == 0) return 1;
        if (index == nums.size()) return 0;

        if (memo[index][need] != -1) {
            return memo[index][need];
        }

        int dontInclude = solve(memo, nums, need, index + 1);
        int include = 0;

        if (need - nums[index] >= 0) {
            include = solve(memo, nums, need - nums[index], index + 1);
        }

        return memo[index][need] = (dontInclude + include);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int zeros = 0;
        vector<int> filtered;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros++;
            else filtered.push_back(nums[i]);
        }

        int sum = accumulate(filtered.begin(), filtered.end(), 0);
        if (abs(target) > sum || (sum + target) & 1) return 0;

        int need = (sum + target) / 2;
        if (need < 0) return 0;

        int n = filtered.size();
        table memo(n, vector<int>(need + 1, -1));

        int ways = solve(memo, filtered, need, 0);
        return ways * (1 << zeros);
    }
};