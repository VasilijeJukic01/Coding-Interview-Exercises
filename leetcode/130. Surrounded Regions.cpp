class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void bfs(vector<vector<char>>& board, int startI, int startJ) {
        int m = board.size();
        int n = board[0].size();

        queue<array<int, 2>> q;
        q.push({startI, startJ});
        board[startI][startJ] = 'Y';

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            array<int, 2> curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];

            for (int k = 0; k < 4; k++) {
                int nI = i + y[k];
                int nJ = j + x[k];
                if (isSafe(nI, nJ, m, n) && board[nI][nJ] == 'O') {
                    q.push({nI, nJ});
                    board[nI][nJ] = 'Y';
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n - 1] == 'O') bfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m - 1][j] == 'O') bfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                 if (board[i][j] == 'O') board[i][j] = 'X';
                 if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};