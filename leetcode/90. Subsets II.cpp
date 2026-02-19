class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int start, vector<int>& curr) {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            solve(nums, i + 1, curr);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(nums, 0, curr);

        return result;
    }
};