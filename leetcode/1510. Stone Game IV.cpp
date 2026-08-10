#define ALICE 1
#define BOB 0

class Solution {
    using table = vector<vector<int>>;
public:
    bool winnerSquareGame(int n) {
        table dp(n + 1, vector<int>(2, false));
        dp[0][BOB] = true;

        for (int i = 1; i <= n; i++) {
            for (int turn = 0; turn <= 1; turn++) {
                int result = (turn == BOB);
                for (int k = 1; k * k <= i; k++) {
                    int amount = k * k;
                    if (i - amount >= 0) {
                        if (turn == ALICE) {
                            result = result || dp[i - amount][!turn];
                            if (result) break;
                        }
                        else {
                            result = result && dp[i - amount][!turn];
                            if (!result) break;
                        }
                    }
                }
                dp[i][turn] = result;
            }
        }

        return dp[n][ALICE];
    }
};