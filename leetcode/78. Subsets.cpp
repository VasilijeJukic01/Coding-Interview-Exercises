class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int start, vector<int>& curr) {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, i + 1, curr);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(nums, 0, curr);

        return result;
    }
};