class Solution {
    int memo[101][101][101][4];
    const int MOD = 1e9 + 7;
public:
    int solve(string& w1, string& w2, string& t, int i, int j, int k, int mask) {
        if (k == t.size()) {
            if (mask == 3) return 1;
            return 0;
        }

        if (memo[i][j][k][mask] != -1) {
            return memo[i][j][k][mask];
        }

        int total = 0;
        for (int I = i; I < w1.size(); I++) {
            if (w1[I] == t[k]) {
                int maskP = mask | 1;
                int nextCall = solve(w1, w2, t, I + 1, j, k + 1, maskP);
                total = (total + nextCall) % MOD;
            }
        }

        for (int J = j; J < w2.size(); J++) {
            if (w2[J] == t[k]) {
                int maskP = mask | 2;
                int nextCall = solve(w1, w2, t, i, J + 1, k + 1, maskP);
                total = (total + nextCall) % MOD;
            }
        }

        return memo[i][j][k][mask] = total;
    }
    
    int interleaveCharacters(string word1, string word2, string target) {
        memset(memo, -1, sizeof(memo));
        return solve(word1, word2, target, 0, 0, 0, 0);
    }
};