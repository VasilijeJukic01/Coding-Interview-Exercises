class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1, q = -1;

        // Phase 1
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) p = i;
            else if (nums[i-1] == nums[i]) return false;
            else break;
        }
        if (p == -1) return false;

        // Phase 2
        for (int i = p + 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) q = i;
            else if (nums[i-1] == nums[i]) return false;
            else break;
        }
        if (q == -1) return false;

        // Phase 3
        bool phaseDone = false;
        for (int i = q + 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) return false;
            else if (nums[i-1] == nums[i]) return false;
            phaseDone = true;
        }

        return phaseDone;
    }
};