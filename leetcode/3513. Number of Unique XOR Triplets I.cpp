class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // x >= n && x <= 2^b - 1, b=leftmost bit of n
        int n = nums.size();
        if (n == 1 || n == 2) return n;

        int bits = 0;
        int m = n;
        while (m) {
            bits++;
            m >>= 1;
        }

        return pow(2, bits);
    }
};