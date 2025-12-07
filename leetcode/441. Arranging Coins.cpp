class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 1;
        long long end = n;

        int best = 1;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            long long x = mid * (mid + 1) / 2;
            if (x <= n) {
                best = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return best;
    }
};