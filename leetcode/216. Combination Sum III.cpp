class Solution {
public:
    vector<vector<int>> result;

    void solve(int n, int k, vector<int>& curr, int sum, int start) {
        if (sum == n && curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (sum + i > n) break;
            curr.push_back(i);
            solve(n, k, curr, sum + i, i + 1);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(n, k, curr, 0, 1);

        return result;
    }
};