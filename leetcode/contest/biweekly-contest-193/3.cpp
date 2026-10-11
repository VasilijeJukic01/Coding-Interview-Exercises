class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int maxLen = 0, currLen = 0;
        int currRemainder = -1;
        for (int i = 0; i < n; i++) {
            int remainder = nums[i] % k;
            if (remainder == currRemainder) currLen++;
            else {
                if (currLen > 0) {
                    int l = currLen;
                    while (l > 0 && (((long long)(l - 1) * currRemainder) % k)) {
                        l--;
                    }
                    maxLen = max(maxLen, l);
                }
                currLen = 1;
                currRemainder = remainder;
            }
        }

        if (currLen > 0) {
            int l = currLen;
            while (l > 0 && (((long long)(l - 1) * currRemainder) % k)) {
                l--;
            }
            maxLen = max(maxLen, l);
        }

        return maxLen;
    }
};