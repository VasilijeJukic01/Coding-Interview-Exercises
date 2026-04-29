class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        long long total = 0;

        long long pSum = 0;
        long long oddSums = 0, evenSums = 1;
        for (int i = 0; i < n; i++) {
            pSum += arr[i];
            if (pSum & 1) {
                total = (total + evenSums) % mod;
                oddSums++;
            }
            else {
                total = (total + oddSums) % mod;
                evenSums++;
            }
        }

        return total;
    }
};