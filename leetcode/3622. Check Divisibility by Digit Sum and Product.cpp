class Solution {
public:
    bool checkDivisibility(int n) {
        int copy = n;
        int sum = 0, product = 1;

        while (copy) {
            int dig = copy % 10;
            sum += dig;
            product *= dig;
            copy /= 10;
        }

        return n % (sum + product) == 0;
    }
};