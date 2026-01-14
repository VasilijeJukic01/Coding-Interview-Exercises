class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        int deleted = 0;
        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                swap(nums[write], nums[read]);
                write++;
                deleted++;
            }
        }

        return deleted;
    }
};