class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 0;
        int counter = 0;
        int prev = nums[0];
        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] == prev) counter++;
            else counter = 1;

            if (counter < 3) {
                nums[write] = nums[read];
                write++;
            }
            prev = nums[read];
        }

        return write;
    }
};