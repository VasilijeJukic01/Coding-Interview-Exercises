class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();

        long long maxProd = LONG_MIN;
        int first, second;
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (nums[i] <= nums[j] || (nums[i] + nums[j] != target)) {
                    continue;
                }
                long long prod = (long long)nums[i] * nums[j];
                if (prod > maxProd) {
                    found = true;
                    maxProd = prod;
                    first = i;
                    second = j;
                }
            }
        }

        if (!found) return {-1, -1};
        return {first, second};
    }
};