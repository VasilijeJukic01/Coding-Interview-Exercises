class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n = nums.size();

        vector<int> dp(n, 0);
        vector<int> counts(n, 1);

        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            int longest = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[j] == longest) {
                        counts[i] += counts[j];
                    }
                    else if (dp[j] > longest) {
                        longest = dp[j];
                        counts[i] = counts[j];
                    }
                }
            }

            dp[i] = 1 + longest;
            maxLen = max(maxLen, dp[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                total += counts[i];
            }
        }

        return total;
    }
};