class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int minSum) {
        int splits = 0;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum + nums[i] <= minSum) {
                currSum += nums[i];
            }
            else {
                currSum = nums[i];
                splits++;
            }
        }
        if (currSum != 0) splits++;

        if (splits <= k) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = 0, end = 0;

        for (int i = 0; i < nums.size(); i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }

        int best = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canSplit(nums, k, mid)) {
                end = mid - 1;
                best = mid;
            }
            else start = mid + 1;
        }

        return best;
    }
};