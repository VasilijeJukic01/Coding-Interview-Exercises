class Solution {
    using table = vector<vector<int>>;
    const int MOD = 1e9 + 7;
public:
    int solve(table& memo, int n, int i, int j, int currMask, int upperMask) {
        if (j == 3) {
            upperMask = currMask;
            currMask = 0;
            i++;
            j = 0;
        }
        if (i == n) return 1;

        int state = (j << 12) | (currMask << 6) | upperMask;
        if (memo[i][state] != -1) {
            return memo[i][state];
        }

        int total = 0;
        for (int color = 1; color <= 3; color++) {
            int leftColor = currMask & 3;
            int upColor = (upperMask >> ((2 - j) * 2)) & 3;
            if (color == upColor || color == leftColor) continue;

            int nextMask = (currMask << 2) | color;
            total = (total + solve(memo, n, i, j + 1, nextMask, upperMask)) % MOD;
        }

        return memo[i][state] = total;
    }

    int numOfWays(int n) {
        table memo(n, vector<int>((1 << 14) - 1, -1));
        return solve(memo, n, 0, 0, 0, 0);
    }
};