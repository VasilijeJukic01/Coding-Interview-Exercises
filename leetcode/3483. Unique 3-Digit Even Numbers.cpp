class Solution {
public:
    void solve(vector<int>& digits, vector<bool>& used, int curr, int depth, unordered_set<int>& seen) {
        if (depth == 3) {
            if (curr % 2 == 0) seen.insert(curr);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;
            if (depth == 0 && digits[i] == 0) continue;

            used[i] = true;
            solve(digits, used, curr * 10 + digits[i], depth + 1, seen);
            // Backtrack
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        unordered_set<int> seen;
        vector<bool> used(digits.size(), false);
        solve(digits, used, 0, 0, seen);

        return seen.size();
    }
};