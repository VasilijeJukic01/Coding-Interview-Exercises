class Solution {
public:
    int smallestNumber(int n, int t) {
        int start = 1, end = n;
        while (1) {
            int num = n;
            int product = 1;

            if (num == 0) product = 0;

            while (num > 0) {
                product *= (num % 10);
                num /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
        return 0;
    }
};