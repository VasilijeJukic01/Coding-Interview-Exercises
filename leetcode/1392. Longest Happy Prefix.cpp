class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        long long BASE = 256;
        long long MOD = 1e9 + 7;

        long long prefixHash = 0;
        long long suffixHash = 0;

        int longest = 0;
        long long h = 1;
        for (int i = 0, j = n - 1; i < n - 1; i++, j--) {
            prefixHash = (prefixHash * BASE + s[i]) % MOD;
            suffixHash = ((s[j] * h) % MOD + suffixHash) % MOD;
            h = (h * BASE) % MOD;

            if (prefixHash == suffixHash) {
                longest = i + 1;
            }
        }

        return s.substr(0, longest);
    }
};