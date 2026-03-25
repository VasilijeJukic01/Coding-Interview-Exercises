class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string copy = a;
        while (a.size() < b.size()) {
            a += copy;
        }
        a += copy;

        long long BASE = 256;
        long long MOD = 1e9 + 7;

        long long h = 1;
        for (int i = 0; i < b.size() - 1; i++) {
            h = (h * BASE) % MOD;
        }

        long long patternHash = 0;
        long long stringHash = 0;
        for (int i = 0; i < b.size(); i++) {
            patternHash = (patternHash * BASE + b[i]) % MOD;
            stringHash = (stringHash * BASE + a[i]) % MOD;
        }

        int aLen = a.size();
        int bLen = b.size();
        for (int i = 0; i <= aLen - bLen; i++) {
            if (patternHash == stringHash) {
                int endPoint = i + bLen - 1;
                return endPoint / copy.size() + 1;
            }
            stringHash = (((stringHash - a[i] * h) % MOD) % MOD + MOD) % MOD;
            stringHash = (stringHash * BASE) % MOD;
            stringHash = (stringHash + a[i + bLen]) % MOD;
        }

        return -1;
    }
};