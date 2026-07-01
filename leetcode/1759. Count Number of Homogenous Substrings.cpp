class Solution {
    const int MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int total = 0;

        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[left] == s[right]) {
                total = (total + right - left + 1) % MOD;
            }
            else {
                left = right;
                total = (total + 1) % MOD;
            }
        }

        return total;
    }
};