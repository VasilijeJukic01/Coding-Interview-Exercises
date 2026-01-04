class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<int> rowMap(10, 0);
            vector<int> colMap(10, 0);
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    rowMap[x]++;
                    if (rowMap[x] > 1) return false;
                }
                if (board[j][i] != '.') {
                    int y = board[j][i] - '0';
                    colMap[y]++;
                    if (colMap[y] > 1) return false;
                }
            }
        }

        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                vector<int> boxMap(10, 0);
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        int x = board[k][l] - '0';
                        boxMap[x]++;
                        if (boxMap[x] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};