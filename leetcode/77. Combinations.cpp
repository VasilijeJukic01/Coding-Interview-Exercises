class Solution {
public:
    vector<vector<int>> result;

    void solve(int n, int k, vector<int>& curr, int start) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            solve(n, k, curr, i + 1);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n, k, curr, 1);

        return result;
    }
};