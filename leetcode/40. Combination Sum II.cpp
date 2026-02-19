class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& cand, int t, vector<int>& curr, int sum, int start) {
        if (sum == t) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < cand.size(); i++) {
            if (i > start && cand[i] == cand[i - 1]) continue;
            if (sum + cand[i] > t) break;
            
            curr.push_back(cand[i]);
            solve(cand, t, curr, sum + cand[i], i + 1);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, curr, 0, 0);

        return result;
    }
};