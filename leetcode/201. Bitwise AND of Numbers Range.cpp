class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int b = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            b++;
        }
        return left << b;
    }
};