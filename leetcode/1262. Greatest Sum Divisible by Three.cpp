class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp = dp;
            for (int k = 0; k < 3; k++) {
                int sum = nums[i] + dp[k];
                temp[sum % 3] = max(temp[sum % 3], sum);
            }
            dp = temp;
        }

        return dp[0];
    }
};