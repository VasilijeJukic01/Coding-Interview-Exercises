class Solution {
    double log3(double x) {
        return log(x) / log(3);
    }
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        double x = log3(n);
        return abs(x - round(x)) < 1e-12;
    }
};