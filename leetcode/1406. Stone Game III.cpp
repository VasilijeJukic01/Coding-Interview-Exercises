class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + stoneValue[i];
        }

        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int take1 = -1e9, take2 = -1e9, take3 = -1e9;
            if (i + 1 < n + 1) take1 = pSum[i + 1] - pSum[i] - dp[i + 1];
            if (i + 2 < n + 1) take2 = pSum[i + 2] - pSum[i] - dp[i + 2];
            if (i + 3 < n + 1) take3 = pSum[i + 3] - pSum[i] - dp[i + 3];
            
            dp[i] = max({take1, take2, take3});
        }

        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};