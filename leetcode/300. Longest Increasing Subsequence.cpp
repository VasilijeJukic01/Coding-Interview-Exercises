class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Smallest ending number for sequnce of length L
        vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            }
            else {
                int start = 0;
                int end = dp.size() - 1;

                int write = 0;
                while (start <= end) {
                    int mid = start + (end - start) / 2;

                    if (nums[i] > dp[mid]) start = mid + 1;
                    else {
                        end = mid - 1;
                        write = mid;
                    }
                }

                dp[write] = nums[i];
            }
        }

        return dp.size();
    }
};