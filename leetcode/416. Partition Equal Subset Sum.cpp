class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int n = nums.size();
        int target = sum / 2;

        vector<bool> currItem(target + 1, false);
        currItem[0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int w = target; w >= 1; w--) {
                bool dontInclude = currItem[w];
                bool include = false;
                if (w - nums[i] >= 0) {
                    include = currItem[w - nums[i]];
                }
                currItem[w] = include || dontInclude;
            }
        }
        
        return currItem[target];
    }
};