class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;

        int zeroCounter = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCounter++;
            while (zeroCounter > 1) {
                if (nums[left] == 0) zeroCounter--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen - 1;
    }
};