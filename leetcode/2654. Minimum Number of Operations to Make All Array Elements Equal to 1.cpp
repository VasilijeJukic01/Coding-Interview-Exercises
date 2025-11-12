class Solution {
public:
    int gcd(int m, int n) {
        while (m != 0 && n != 0) {
            m = m % n;
            m ^= n;
            n ^= m;
            m ^= n;
        }
        return max(m, n);
    }

    int minOperations(vector<int>& nums) {
        int len = nums.size();
        int ones = 0;

        // If we already have 1s
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) ones++;
        }
        if (ones != 0) return len - ones;

        // If we dont have 1s
        int minArrLen = INT_MAX;

        for (int left = 0; left < len; left++) {
            int gcdAcc = nums[left];
            for (int right = left + 1; right < len; right++) {
                if (gcdAcc == 1) break;
                
                gcdAcc = gcd(gcdAcc, nums[right]);
                if (gcdAcc == 1) {
                    minArrLen = min(minArrLen, right - left + 1);
                }
            }
            if (minArrLen == 2) break;
        }

        if (minArrLen == INT_MAX) return -1;
        return len - 1 + minArrLen - 1;
    }
};