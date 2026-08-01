class Solution {
    using ll = long long;
public:
    bool solve(vector<int>& nums, int i, int j, ll p1, ll p2, bool first) {
        if (p1 >= p2 && i > j) return true;
        if (i > j) return false;

        int n = nums.size();

        bool left = false, right = false;
        if (i < n) {
            if (first) p1 += nums[i];
            else p2 += nums[i];
            left = left || solve(nums, i + 1, j, p1, p2, !first);
            // Backtrack
            if (first) p1 -= nums[i];
            else p2 -= nums[i];
        }
        if (j >= 0) {
            if (first) p1 += nums[j];
            else p2 += nums[j];
            right = right || solve(nums, i, j - 1, p1, p2, !first);
            // Backtrack
            if (first) p1 -= nums[j];
            else p2 -= nums[j];
        }

        if (first) return left || right;
        return left && right;
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1, 0, 0, true);
    }
};