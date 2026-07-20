class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        long long steps = n / 2;
        return (long long) s + steps * (m - 1) + 1;
    }
};