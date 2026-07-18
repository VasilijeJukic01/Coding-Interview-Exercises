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

    int findGCD(vector<int>& nums) {
        int minima = INT_MAX;
        int maxima = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            minima = min(minima, nums[i]);
            maxima = max(maxima, nums[i]);
        }

        return gcd(minima, maxima);
    }
};