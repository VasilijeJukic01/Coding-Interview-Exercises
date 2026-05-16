class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        int minimum = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            minimum = min(minimum, nums[mid]);
            if (nums[mid] == nums[start]) {
                start += 1;
            }
            else if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return minimum;
    }
};