class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> prefSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + nums[i];
        }

        int result = INT_MAX;
        for (int i = 0; i < n + 1; i++) {
            // Compress Window
            while (!dq.empty() && prefSum[i] - prefSum[dq.front()] >= k) {
                result = min(result, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefSum[i] < prefSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }

        if (result == INT_MAX) return -1;
        return result;
    }
};