class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() == 0) return "";

        long long BASE = 256;
        long long MOD = 1e9 + 7;

        long long prefixHash = 0;
        long long suffixHash = 0;

        int longest = 0;

        long long h = 1;
        for (int i = 0; i < s.size(); i++) {
            prefixHash = (prefixHash * BASE + s[i]) % MOD;
            suffixHash = ((s[i] * h) % MOD + suffixHash) % MOD;
            h = (h * BASE) % MOD;

            if (prefixHash == suffixHash) {
                longest = i + 1;
            }
        }

        string need = s.substr(longest);
        reverse(need.begin(), need.end());
        return need + s;
    }
};