class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1, end = num;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            long long x = mid * mid;
            if (x == num) return true;
            else if (num < x) end = mid - 1;
            else start = mid + 1;
        }

        return false;
    }
};