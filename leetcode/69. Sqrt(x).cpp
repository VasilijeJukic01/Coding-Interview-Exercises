class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;

        long long save = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long p = mid * mid;
            
            if (p == x) return mid;
            if (p > x) end = mid - 1;
            else {
                save = mid;
                start = mid + 1;
            }
        }

        return save;
    }
};