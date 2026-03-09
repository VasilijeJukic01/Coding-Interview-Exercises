class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> heights(n, 0);
        
        int total = 0;
        for (int i = 0; i < m; i++) {
            stack<int> s;
            vector<int> dp(n, 0);
            for (int j = 0; j < n; j++) {
                // Extend/Collapse
                if (mat[i][j] == 1) heights[j]++;
                else heights[j] = 0;

                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    s.pop();
                }

                if (s.empty()) dp[j] = heights[j] * (j + 1);
                else dp[j] = dp[s.top()] + heights[j] * (j - s.top());

                s.push(j);
                total += dp[j];
            }
        }

        return total;
    }
};