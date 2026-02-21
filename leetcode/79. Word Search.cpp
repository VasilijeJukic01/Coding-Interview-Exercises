class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    using grid = vector<vector<char>>;

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    bool dfs(grid& board, string& word, int index, int i, int j) {
        if (index == word.size()) return true;

        int ch = board[i][j];
        board[i][j] = '@';

        for (int k = 0; k < 4; k++) {
            int nI = i + dy[k];
            int nJ = j + dx[k];

            if (!isSafe(nI, nJ, board.size(), board[0].size())) continue;
            if (board[nI][nJ] == word[index]) {
                if (dfs(board, word, index + 1, nI, nJ)) return true;
            }
        }

        // Backtrack
        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 1, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};