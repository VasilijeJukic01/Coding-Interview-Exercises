class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int i = 0;
        while (left <= right) {
            if (i > right) break;
            if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
            }
            
            if (nums[i] != 2) i++;
        }
    }
};