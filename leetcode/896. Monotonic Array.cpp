class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;

        bool increasing;

        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                increasing = true;
                break;
            }
            if (nums[i-1] > nums[i]) {
                increasing = false;
                break;
            }
        }

        i++;

        for (; i < nums.size(); i++) {
            if (increasing && nums[i-1] > nums[i]) return false;
            if (!increasing && nums[i-1] < nums[i]) return false;
        }

        return true;
    }
};