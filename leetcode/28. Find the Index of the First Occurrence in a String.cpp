class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        long long BASE = 256;
        long long MOD = 1e9 + 7;
        long long h = 1;

        for (int i = 0; i < m - 1; i++) {
            h = (h * BASE) % MOD;
        }

        long long stringHash = 0;
        long long patternHash = 0;
        for (int i = 0; i < m; i++) {
            stringHash = (stringHash * BASE + haystack[i]) % MOD;
            patternHash = (patternHash * BASE + needle[i]) % MOD;
        }

        for (int i = 0; i <= n - m; i++) {
            if (stringHash == patternHash) {
                bool valid = true;
                for (int k = i; k < i + m; k++) {
                    if (haystack[k] != needle[k - i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return i;
            }

            // Drop leftmost
            stringHash = (stringHash - haystack[i] * h) % MOD;
            stringHash = (stringHash % MOD + MOD) % MOD;
            // Shift hash left
            stringHash = (stringHash * BASE) % MOD;
            // Add incoming
            stringHash = (stringHash + haystack[i + m]) % MOD;
        }

        return -1;
    }
};