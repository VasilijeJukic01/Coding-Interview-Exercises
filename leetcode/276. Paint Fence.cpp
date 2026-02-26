class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 1) return k;

        int first = k;
        int second = k * k;

        int curr = second;
        for (int i = 2; i < n; i++) {
            curr = (first + second) * (k - 1);
            first = second; 
            second = curr; 
        }

        return curr;
    }
};