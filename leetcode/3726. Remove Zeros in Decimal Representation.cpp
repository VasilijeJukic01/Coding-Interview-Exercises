class Solution {
public:
    long long removeZeros(long long n) {
        long long m = 0;
        long long p = 1;

        while (n) {
            int digit = n % 10;
            if (digit != 0) {
                m += digit * p;
                p *= 10;
            }
            n /= 10;
        }

        return m;
    }
};