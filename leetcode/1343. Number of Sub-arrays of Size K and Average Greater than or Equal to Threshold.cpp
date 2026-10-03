class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + arr[i]; 
        }

        int total = 0;
        for (int left = 0, right = k; right <= n; right++, left++) {
            int sum = pSum[right] - pSum[left];
            if (sum / k >= threshold) total++;
        }

        return total;
    }
};