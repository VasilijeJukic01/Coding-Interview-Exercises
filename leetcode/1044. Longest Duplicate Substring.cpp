class Solution {
public:
    string exists(string& s, int len, int n) {
        long long BASE = 256;
        long long MOD1 = 1e9 + 7;
        long long MOD2 = 1e9 + 9;

        long long h1 = 1;
        long long h2 = 1;
        for (int i = 0; i < len - 1; i++) {
            h1 = (h1 * BASE) % MOD1;
            h2 = (h2 * BASE) % MOD2;
        }

        long long hash1 = 0;
        long long hash2 = 0;
        for (int i = 0; i < len; i++) {
            hash1 = (hash1 * BASE + s[i]) % MOD1;
            hash2 = (hash2 * BASE + s[i]) % MOD2;
        }

        unordered_set<long long> visited;
        for (int i = 0; i <= n - len; i++) {
            long long hash = (hash1 << 32) | hash2;
            if (visited.find(hash) != visited.end()) {
                return s.substr(i, len);
            }
            visited.insert(hash);
            
            if (i < n - len) {
                hash1 = (((hash1 - s[i] * h1) % MOD1) % MOD1 + MOD1) % MOD1;
                hash1 = (hash1 * BASE) % MOD1;
                hash1 = (hash1 + s[i + len]) % MOD1;

                hash2 = (((hash2 - s[i] * h2) % MOD2) % MOD2 + MOD2) % MOD2;
                hash2 = (hash2 * BASE) % MOD2;
                hash2 = (hash2 + s[i + len]) % MOD2;
            }   
        }

        return "";
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        int start = 1, end = n - 1;

        string longest = "";
        while (start <= end) {
            int mid = start + (end - start) / 2;

            string result = exists(s, mid, n);
            if (!result.empty()) {
                longest = result;
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return longest;
    }
};