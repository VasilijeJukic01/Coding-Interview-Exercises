class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total = 0;
        int maximum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maximum = max(maximum, nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            total += maximum - nums[i];
        }

        return total;
    }
};