class Solution {
public:
    int countCommas(int n) {
        int total = 0;
        for (int i = 1000; i <= n; i++) {
            total++;
        }
        return total;
    }
};