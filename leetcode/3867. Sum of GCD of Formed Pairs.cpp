class Solution {
public:
    int gcd(int x, int y) {
        while (y) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int currMax = 0;
        vector<int> prefixGcd;
        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            prefixGcd.push_back(gcd(nums[i], currMax));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
        }

        return sum;
    }
};