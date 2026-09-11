class Solution {
    const long long BOUND1 = 1e6 - 1;
    const long long BOUND2 = 1e9 - 1;
    const long long BOUND3 = 1e12 - 1;
    const long long BOUND4 = 1e15 - 1;
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;

        long long total = 0;

        long long ub = min(n, BOUND1);
        total += (ub - 999);
        
        if (n > BOUND1) {
            ub = min(n, BOUND2);
            total += 2 * (ub - BOUND1);
        }
        
        if (n > BOUND2) {
            ub = min(n, BOUND3);
            total += 3 * (ub - BOUND2);
        }
        
        if (n > BOUND3) {
            ub = min(n, BOUND4);
            total += 4 * (ub - BOUND3);
        }
        
        if (n > BOUND4) total += 5 * (n - BOUND4);

        return total;
    }
};