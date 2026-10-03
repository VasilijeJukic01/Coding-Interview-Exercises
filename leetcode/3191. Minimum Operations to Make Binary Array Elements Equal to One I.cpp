class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for (int left = 0; left < nums.size(); left++) {
            if (nums[left] == 1) continue;
            if (left + 3 > nums.size()) return -1;

            for (int right = left; right < left + 3; right++) {
                nums[right] = !nums[right];
            }
            ops++;
        }

        return ops;
    }
};