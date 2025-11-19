class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int minimum = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
            minimum = min(minimum, nums[i]);
        }

        return firstMax + secondMax - minimum;
    }
};