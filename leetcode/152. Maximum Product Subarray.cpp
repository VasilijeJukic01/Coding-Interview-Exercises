class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        int currMax = nums[0], currMin = nums[0];
        for (int i = 1; i < n; i++) {
            int prevMax = currMax;
            int prevMin = currMin;

            currMax = max(nums[i], prevMax * nums[i]);
            currMax = max(currMax, prevMin * nums[i]);
            maxProd = max(maxProd, currMax);

            currMin = min(nums[i], prevMin * nums[i]);
            currMin = min(currMin, prevMax * nums[i]);
        }

        return maxProd;
    }
};