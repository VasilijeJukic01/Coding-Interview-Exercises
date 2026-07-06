class Solution {
    using p = array<int, 2>;
    using table = vector<vector<p>>;
    const int MOD = 1e9 + 7;
public:
    p solve(table& memo, vector<string>& board, int i, int j, int n) {
        if (i == 0 && j == 0) return {0, 1};

        if (memo[i][j][0] != -1) return memo[i][j];

        p up = {0, 0}, left = {0, 0}, upLeft = {0, 0};
        if (i > 0 && board[i - 1][j] != 'X') {
            up = solve(memo, board, i - 1, j, n);
        }
        if (j > 0 && board[i][j - 1] != 'X') {
            left = solve(memo, board, i, j - 1, n);
        }
        if (i > 0 && j > 0 && board[i - 1][j - 1] != 'X') {
            upLeft = solve(memo, board, i - 1, j - 1, n);
        }

        int currScore = board[i][j] - '0';
        if (i == n - 1 && j == n - 1) currScore = 0;

        vector<p> data;
        data.push_back(up);
        data.push_back(left);
        data.push_back(upLeft);

        int maxScore = INT_MIN;
        int count = 0;
        for (int k = 0; k < 3; k++) {
            if (data[k][1] == 0) continue;

            if (data[k][0] == maxScore) {
                count = (count + data[k][1]) % MOD;
            }
            else if (data[k][0] > maxScore) {
                maxScore = data[k][0];
                count = data[k][1];
            }
        }

        if (maxScore == INT_MIN) {
            return memo[i][j] = {0, 0};
        }
        return memo[i][j] = {currScore + maxScore, count};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        table memo(n, vector<p>(n, {-1, -1}));
        p maxScore = solve(memo, board, n - 1, n - 1, n);

        return {maxScore[0], maxScore[1]};
    }
};