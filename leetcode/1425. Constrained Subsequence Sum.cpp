class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> dp(n, 0);
        int best = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }
            if (!dq.empty() && dp[dq.front()] > 0) {
                dp[i] += dp[dq.front()];
            }
            while (!dq.empty() && dp[dq.back()] < dp[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            best = max(best, dp[i]);
        }
        
        return best;
    }
};