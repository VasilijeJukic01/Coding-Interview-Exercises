class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int i = 0; i < n; i++) {
            total ^= nums[i];
        }

        if (total) return n;

        for (int i = 0; i < n; i++) {
            if (total ^ nums[i]) return n - 1;
        }

        return 0;
    }
};