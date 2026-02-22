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

    void solve(board& b, int n, int row, vector<bool>& columns, vector<board>& result) {
        if (row > n) return;

        if (row == n) {
            result.push_back(b);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!isSafe(row, c, b, columns)) continue;

            b[row][c] = 'Q';
            columns[c] = true;
            solve(b, n, row + 1, columns, result);
            // Backtrack
            b[row][c] = '.';
            columns[c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<board> result;
        vector<bool> columns(n, false);
        board b(n, string(n, '.'));

        solve(b, n, 0, columns, result);
        return result;
    }
};