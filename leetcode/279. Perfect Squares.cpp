class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        int x = 1;
        int y = 2;
        while (x <= n) {
            nums.push_back(x);
            x = y * y;
            y++;
        }

        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int w = 1; w <= n; w++) {
                int dontInclude = dp[w];
                int include = INT_MAX - 1;
                if (w - nums[i] >= 0) {
                    include = 1 + dp[w - nums[i]];
                }

                dp[w] = min(dontInclude, include);
            }
        }

        return dp[n];
    }
};