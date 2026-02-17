class Solution {
public:
    double divideAndConquer(double x, long long n) {
        if (n == 0) return 1;

        double half = divideAndConquer(x, n / 2);

        if (n & 1) return half * half * x;
        return half * half;
    }

    double myPow(double x, int n) {
        long long num = n;
        if (num < 0) {
            x = 1 / x;
            num = -num;
        }

        return divideAndConquer(x, num);
    }
};