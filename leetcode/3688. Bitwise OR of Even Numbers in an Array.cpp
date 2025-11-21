class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                if (result == 0) result = nums[i];
                else result |= nums[i];
            }
        }

        return result;
    }
};