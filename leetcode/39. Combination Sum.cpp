class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int t, vector<int>& curr, int sum, int start) {
        if (sum > t) return;
        if (sum == t) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            solve(candidates, t, curr, sum + candidates[i], i);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, target, curr, 0, 0);

        return result;
    }
};