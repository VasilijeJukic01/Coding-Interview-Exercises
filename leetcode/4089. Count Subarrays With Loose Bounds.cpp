class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total = 0;
        
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] >= minK && nums[right] <= maxK) {
                total += (right - left + 1);
            }
            else left = right + 1;
        }

        return total;
    }
};