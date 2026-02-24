class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int max1 = second;
        for (int i = 2; i < n - 1; i++) {
            max1 = max(second, first + nums[i]);
            first = second;
            second = max1;
        }

        first = nums[1];
        second = max(nums[1], nums[2]);
        int max2 = second;
        for (int i = 3; i < n; i++) {
            max2 = max(second, first + nums[i]);
            first = second;
            second = max2;
        }

        return max(max1, max2);
    }
};