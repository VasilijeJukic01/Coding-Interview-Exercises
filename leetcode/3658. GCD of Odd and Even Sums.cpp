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

    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (i & 1) sumOdd += i;
            else sumEven += i;
        }

        return gcd(sumOdd, sumEven);
    }
};