class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];

        int min1 = 100, min2 = 100;
        int min1Index = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min1 = nums[i];
                min1Index = i;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (i != min1Index) {
                min2 = min(min2, nums[i]);
            }
        }

        return first + min1 + min2;
    }
};