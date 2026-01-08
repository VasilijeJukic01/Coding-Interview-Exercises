class Solution {
public:

    int sumSquares(int n) {
        int num = 0;
        while (n) {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        return num;
    }

    bool isHappy(int n) {
        unordered_set<int> s;

        while (true) {
            n = sumSquares(n);
            if (n == 1) return true;
            if (s.find(n) != s.end()) return false;
            s.insert(n);
        }
    }
};