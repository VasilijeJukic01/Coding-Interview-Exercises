class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);

        // Prefix Product
        for (int i = 1; i < n; i++) {
            v[i] = v[i - 1] * nums[i - 1];
        }

        // Suffix Product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            v[i] *= suffix;
            suffix *= nums[i];
        }

        return v;
    }
};