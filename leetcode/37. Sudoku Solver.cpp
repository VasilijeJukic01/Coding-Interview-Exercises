class Solution {
public:
    using grid = vector<vector<char>>;

    bool canPlace(int val, int row, int col, grid& board) {
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == '.') continue;
            if ((board[r][col] - '0') == val) return false;
        }

        for (int c = 0; c < 9; c++) {
            if (board[row][c] == '.') continue;
            if ((board[row][c] - '0') == val) return false;
        }

        int blockR = (row / 3) * 3;
        int blockC = (col / 3) * 3;

        for (int r = blockR; r < blockR + 3; r++) {
            for (int c = blockC; c < blockC + 3; c++) {
                if (board[r][c] == '.') continue;
                if ((board[r][c] - '0') == val) return false;
            }
        }

        return true;
    }

    bool solve(grid& board, int row, int col) {
        if (col == 9) {
            row++;
            col = 0;
        }
        if (row == 9) return true;

        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }

        for (int val = 1; val <= 9; val++) {
            if (canPlace(val, row, col, board)) {
                board[row][col] = val + '0';
                if (solve(board, row, col + 1)) {
                    return true;
                }
                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};