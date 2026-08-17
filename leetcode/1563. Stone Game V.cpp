class Solution {
    using table = vector<vector<int>>;
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + stoneValue[i];
        }

        table dp(n + 1, vector<int>(n + 1, 0));
        for (int s = n - 1; s >= 0; s--) {
            for (int e = 0; e < n; e++) {
                int result = 0;
                for (int mid = s; mid < e; mid++) {
                    int leftSum = pSum[mid + 1] - pSum[s];
                    int rightSum = pSum[e + 1] - pSum[mid + 1];

                    if (leftSum == rightSum) {
                        int throwLeft = rightSum + dp[mid + 1][e];
                        int throwRight = leftSum + dp[s][mid];
                        result = max(result, max(throwLeft, throwRight));
                    }
                    else if (leftSum > rightSum) {
                        result = max(result, rightSum + dp[mid + 1][e]);
                    }
                    else result = max(result, leftSum + dp[s][mid]);
                }
                dp[s][e] = result;
            }
        }

        return dp[0][n - 1];
    }
};