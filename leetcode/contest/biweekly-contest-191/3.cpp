class Solution {
public:
    int solve(vector<int>& memo, int target) {
        if (target == 0) return 0;
    
        if (memo[target] != -1) return memo[target];
        
        int best = 1e9;
        for (int k = 1; ; k++) {
            int score = k * (k + 1) / 2;
            if (score > target) break;
            
            if (score == target) best = min(best, k);
            else {
                int val = k + 1 + solve(memo, target - score);
                best = min(best, val);
            }
        }

        return memo[target] = best;
    }
    
    int minDays(int n) {
        vector<int> memo(n + 1, -1);
        return solve(memo, n);
    }
};