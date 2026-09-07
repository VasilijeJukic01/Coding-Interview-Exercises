class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> score(n);

        int currMin = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            currMin = min(currMin, nums[i]);
            score[i] = currMin;
        }

        int currMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            if (currMax - score[i] <= k) return i;
        }

        return -1;
    }
};