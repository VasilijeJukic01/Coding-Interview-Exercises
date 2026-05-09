class Solution {
public:
    bool solve(vector<int>& m, int map, int w, int sides, int target, int n, int start) {
        if (sides == 0) return true; 
        if (w == 0) {
            return solve(m, map, target, sides - 1, target, n, 0);
        }

        for (int k = start; k < n; k++) {
            if (map & (1 << k)) continue;
            if (w - m[k] >= 0) {
                map |= (1 << k);
                if (solve(m, map, w - m[k], sides, target, n, k + 1)) {
                    return true;
                }
                // Backtrack
                map ^= (1 << k);
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;

        int target = sum / 4;
        int map = 0;

        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > target) return false;

        return solve(matchsticks, map, target, 4, target, n, 0);
    }
};