class Solution {
public:
    long long reverse(int n) {
        long long res = 0LL;
        while (n) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return res;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};