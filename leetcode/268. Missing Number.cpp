class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int accumulator = 0;
        for (int i = 1; i <= nums.size(); i++) {
            accumulator ^= i;
        }

        for (int i = 0; i < nums.size(); i++) {
            accumulator ^= nums[i];
        }

        return accumulator;
    }
};