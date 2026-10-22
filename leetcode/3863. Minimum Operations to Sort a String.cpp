class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted) return 0;
        if (s.size() == 2) return -1;

        int firstCharIdx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == sorted[0]) {
                firstCharIdx = i;
                break;
            }
        }

        int lastCharIdx = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == sorted[n - 1]) {
                lastCharIdx = i;
                break;
            }
        }

        if (firstCharIdx == 0 || lastCharIdx == n - 1) return 1;
        if (firstCharIdx < s.size() - 1 || lastCharIdx > 0) return 2;
        return 3;
    }
};