class Solution {
public:
    void solve(vector<int>& nums, int start, int acc, int& total) {
        total += acc;

        for (int i = start; i < nums.size(); i++) {
            acc ^= nums[i];
            solve(nums, i + 1, acc, total);
            // Backtrack
            acc ^= nums[i];
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        solve(nums, 0, 0, total);
        return total;
    }
};