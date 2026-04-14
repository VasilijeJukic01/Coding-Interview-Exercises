// Memo
/*
class Solution {
public:
    using grid = vector<vector<int>>;

    int solveUpper(grid& memo, grid& f, int n, int i, int j) {
        if (i == n - 1) {
            if (j == n - 1) return 0;
            return -1e9;
        }
        if (j <= i || j >= n || i >= n) return -1e9;

        if (memo[i][j] != -1) return memo[i][j];

        int move1 = solveUpper(memo, f, n, i + 1, j - 1);
        int move2 = solveUpper(memo, f, n, i + 1, j);
        int move3 = solveUpper(memo, f, n, i + 1, j + 1);

        return memo[i][j] = f[i][j] + max({move1, move2, move3});
    }

    int solveLower(grid& memo, grid& f, int n, int i, int j) {
        if (j == n - 1) {
            if (i == n - 1) return 0;
            return -1e9;
        }
        if (j >= i || j >= n || i >= n) return -1e9;

        if (memo[i][j] != -1) return memo[i][j];

        int move1 = solveLower(memo, f, n, i - 1, j + 1);
        int move2 = solveLower(memo, f, n, i, j + 1);
        int move3 = solveLower(memo, f, n, i + 1, j + 1);

        return memo[i][j] = f[i][j] + max({move1, move2, move3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
    
        int total = 0;
        // Green
        for(int i = 0; i < n; i++) {
            total += fruits[i][i];
        }
        grid memo(n, vector<int>(n, -1));
        // Red
        total += solveUpper(memo, fruits, n, 0, n - 1);
        // Blue
        total += solveLower(memo, fruits, n, n - 1, 0);

        return total;
    }
};
*/

class Solution {
public:
    using grid = vector<vector<long long>>;

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
    
        int total = 0;
        // Green
        for(int i = 0; i < n; i++) {
            total += fruits[i][i];
        }
        grid dp1(n + 1, vector<long long>(n + 1, -1e9));
        grid dp2(n + 1, vector<long long>(n + 1, -1e9));
        dp1[n - 1][n - 1] = 0;
        dp2[n - 1][n - 1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (i == n - 1 && j == n - 1) continue;
                int move1 = dp1[i + 1][j - 1];
                int move2 = dp1[i + 1][j];
                int move3 = dp1[i + 1][j + 1];

                dp1[i][j] = fruits[i][j] + max({move1, move2, move3});
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            for (int i = n - 1; i > j; i--) {
                if (i == n - 1 && j == n - 1) continue;
                int move1 = dp2[i - 1][j + 1];
                int move2 = dp2[i][j + 1];
                int move3 = dp2[i + 1][j + 1];
                
                dp2[i][j] = fruits[i][j] + max({move1, move2, move3});
            }
        }

        // Red + Blue
        total += dp1[0][n - 1] + dp2[n - 1][0];

        return total;
    }
};