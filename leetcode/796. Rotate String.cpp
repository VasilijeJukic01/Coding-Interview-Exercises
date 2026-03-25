class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        long long BASE = 256;
        long long MOD = 1e9 + 7;

        int n = goal.size();
        long long h = 1;
        for (int i = 0; i < n - 1; i++) {
            h = (h * BASE) % MOD;
        }

        long long patternHash = 0;
        long long stringHash = 0;
        for (int i = 0; i < n; i++) {
            patternHash = (patternHash * BASE + goal[i]) % MOD;
            stringHash = (stringHash * BASE + s[i]) % MOD;
        }

        for (int i = 0; i < n; i++) {
            if (patternHash == stringHash) {
                bool valid = true;
                for (int j = i; j < i + n; j++) {
                    if (s[j % n] != goal[j - i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }

            stringHash = (stringHash - s[i] * h) % MOD;
            stringHash = (stringHash % MOD + MOD) % MOD;
            stringHash = (stringHash * BASE) % MOD;
            stringHash = (stringHash + s[i]) % MOD;
        }

        return false;
    }
};