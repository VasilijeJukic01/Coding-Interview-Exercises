class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int currMaxSum = nums[0], currMinSum = nums[0];
        int maxSum = currMaxSum, minSum = currMinSum;
        int totalSum = nums[0];
        for (int i = 1; i < n; i++) {
            currMaxSum = max(nums[i], currMaxSum + nums[i]);
            currMinSum = min(nums[i], currMinSum + nums[i]);
            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);

            totalSum += nums[i];
        }

        // All negatives -> return the greatest
        if (maxSum < 0) return maxSum;
        return max(totalSum - minSum, maxSum);
    }
};