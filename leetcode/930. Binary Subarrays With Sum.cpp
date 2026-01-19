class Solution {
public:
    int count(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int total = 0;

        long long currSum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            while (currSum > k) {
                currSum -= nums[left];
                left++;
            }
            total += (right - left + 1);
        }

        return total;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // (arrays with goal <= sum) - (arrays with <= goal-1 sum)
        return count(nums, goal) - count(nums, goal - 1);
    }
};