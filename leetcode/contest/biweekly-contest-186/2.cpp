class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int maxI = nums[0];
        int bestSum = nums[0] + nums[k];
        for (int j = k + 1; j < n; j++) {
            if (nums[j - k] > maxI) {
                maxI = nums[j - k];
            }
            if (maxI + nums[j] > bestSum) {
                bestSum = maxI + nums[j];
            }
        }

        return bestSum;
    }
};