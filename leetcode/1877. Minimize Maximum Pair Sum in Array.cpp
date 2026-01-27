class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int best = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
            best = max(best, nums[i] + nums[j]);
        }

        return best;
    }
};