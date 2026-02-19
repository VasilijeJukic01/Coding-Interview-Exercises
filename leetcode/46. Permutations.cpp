class Solution {
public:
    vector<vector<int>> result;
    vector<bool> visited;

    void solve(vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            
            curr.push_back(nums[i]);
            visited[i] = true;
            solve(nums, curr);
            // Backtrack
            curr.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), 0);
        vector<int> curr;
        solve(nums, curr);

        return result;
    }
};