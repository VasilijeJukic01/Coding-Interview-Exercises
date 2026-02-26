class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        // Length of max subset at pos i
        vector<int> dp(n, 1);

        int maxLen = 1;
        int origin = nums[0];
        for (int i = 1; i < n; i++) {
            int longest = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    longest = max(longest, dp[j]);
                }
            }
            dp[i] = 1 + longest;
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                origin = nums[i];
            }
        }

        vector<int> result;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == maxLen && origin % nums[i] == 0) {
                result.push_back(nums[i]);
                maxLen--;
                origin = nums[i];
            }
        }

        return result;
    }
};