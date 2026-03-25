class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int len = n / 2;

        long long BASE = 256;
        long long MOD = 1e9 + 7;

        for (int m = len; m >= 1; m--) {
            if (n % m != 0) continue;

            long long prefixHash = 0;
            for (int i = 0; i < m; i++) {
                prefixHash = (prefixHash * BASE + s[i]) % MOD;
            }

            bool valid = true;
            for (int i = m; i < n; i += m) {
                long long chunkHash = 0;
                for (int k = i; k < i + m; k++) {
                    chunkHash = (chunkHash * BASE + s[k]) % MOD;
                }

                if (prefixHash != chunkHash) {
                    valid = false;
                    break;
                }
            }

            if (valid) return true;
        }

        return false;
    }
};

/*
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        long long p = 256;
        long long MOD = 1e9 + 7;
        
        vector<long long> prefixHash(n + 1, 0);
        vector<long long> powers(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            powers[i + 1] = (powers[i] * p) % MOD;
            prefixHash[i + 1] = (prefixHash[i] + s[i] * powers[i]) % MOD; 
        }
        
        for (int d = n / 2; d >= 1; d--) {
            if (n % d != 0) continue;
            
            // Hash of the first d characters
            long long hash = prefixHash[d];
            int cnt = d;
            long long deg = 1;
            bool found = true;
            
            while (cnt <= n) {
                long long leftSide = (hash * deg) % MOD;
                long long rightSide = (prefixHash[cnt] - prefixHash[cnt - d]) % MOD;
                if (rightSide < 0) rightSide += MOD;
                
                if (leftSide != rightSide) {
                    found = false;
                    break;
                }
                
                deg = (deg * powers[d]) % MOD; 
                cnt += d;
            }
            
            if (found) return true;
        }
        
        return false;
    }
};
*/