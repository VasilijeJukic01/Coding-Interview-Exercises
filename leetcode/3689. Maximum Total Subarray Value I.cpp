class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long minima = LONG_MAX;
        long long maxima = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            minima = min(minima, (long long) nums[i]);
            maxima = max(maxima, (long long) nums[i]);
        }

        return k * (maxima - minima);
    }
};