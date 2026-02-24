class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int first = 1;
        int second = 2;

        int curr;
        for (int i = 3; i <= n; i++) {
            curr = second + first;
            first = second;
            second = curr;
        }

        return curr;
    }
};