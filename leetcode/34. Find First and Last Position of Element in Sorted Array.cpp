class Solution {
public:
    int findPosition(vector<int>& nums, int target, bool first) {
        int pos = -1;
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                pos = mid;
                if (first) end = mid - 1;
                else start = mid + 1;
            }
            else if (target > nums[mid]) start = mid + 1;
            else end = mid - 1;
        }

        return pos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findPosition(nums, target, true);
        int last = findPosition(nums, target, false);

        return {first, last};
    }
};