class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> dp(n, INT_MAX);
        
        int curr = 0;
        int result = INT_MAX;
        int best = INT_MAX;
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            curr += arr[right];
            
            while (left <= right && curr > target) {
                curr -= arr[left];
                left++;
            }
            
            if (curr == target) {
                int len = right - left + 1;
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    result = min(result, len + dp[left - 1]);
                }
                
                best = min(best, len);
            }
            
            dp[right] = best;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};