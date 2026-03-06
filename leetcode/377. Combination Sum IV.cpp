class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int w = 1; w <= target; w++) {
            for (int i = 0; i < nums.size(); i++) {
                if (w - nums[i] >= 0) {
                    dp[w] += dp[w - nums[i]];
                }
            }
        }

        return dp[target];
    }
};