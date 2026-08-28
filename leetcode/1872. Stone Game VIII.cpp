class Solution {
public:
    int solve(vector<int>& memo, vector<int>& pSum, int i) {
        if (i == pSum.size() - 1) return pSum[i];
        
        if (memo[i] != INT_MIN) return memo[i];
        
        int take = pSum[i] - solve(memo, pSum, i + 1);
        int skip = solve(memo, pSum, i + 1);
        
        return memo[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + stones[i];
        }
        
        vector<int> memo(n + 1, INT_MIN);
        return solve(memo, pSum, 2);
    }
};