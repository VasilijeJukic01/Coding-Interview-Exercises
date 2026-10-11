class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int remainder = nums[i] % k;

            for (int j = i; j < n; j++) {
                int remainderP = nums[j] % k;
                if (remainderP != remainder) break;

                int len = j - i + 1;
                long long sum = (long long)(len - 1) * remainder;
                if (sum % k == 0) {
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};