class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int best = INT_MAX;

        int left = 0;
        int currSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            if (currSum >= target) {
                best = min(best, right - left + 1);
            }
            while (currSum >= target) {
                currSum -= nums[left];
                left++;
                if (currSum >= target) {
                    best = min(best, right - left + 1);
                }
            }
        }

        if (best == INT_MAX) return 0;
        return best;
    }
};