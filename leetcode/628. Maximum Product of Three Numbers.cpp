class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int optA = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int optB = nums[n - 1] * nums[1] * nums[0];

        return max(optA, optB);
    }
};