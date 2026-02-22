class Solution {
public:
    using board = vector<string>;

    bool isSafe(int row, int col, board& b, vector<bool>& columns) {
        // Columns
        if (columns[col]) return false;
        // Upper-Left
        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (b[r][c] == 'Q') return false;
            r--;
            c--;
        }
        // Upper-Right
        r = row - 1, c = col + 1;
        while (r >= 0 && c < b.size()) {
            if (b[r][c] == 'Q') return false;
            r--;
            c++;
        }
        return true;
    }

    void solve(board& b, int n, int row, vector<bool>& columns, int& total) {
        if (row > n) return;

        if (row == n) {
            total++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!isSafe(row, c, b, columns)) continue;

            b[row][c] = 'Q';
            columns[c] = true;
            solve(b, n, row + 1, columns, total);
            // Backtrack
            b[row][c] = '.';
            columns[c] = false;
        }
    }

    int totalNQueens(int n) {
        int total = 0;
        vector<bool> columns(n, false);
        board b(n, string(n, '.'));

        solve(b, n, 0, columns, total);
        return total;
    }
};