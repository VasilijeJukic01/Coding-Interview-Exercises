class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;

        int p = 1;
        int x = 0;
        while (n) {
            int dig = n % 10;
            if (dig != 0) {
                x = x + p * dig;
                p *= 10;
                sum += dig;
            }
            n /= 10;
        }

        return (long long) x * sum;
    }
};