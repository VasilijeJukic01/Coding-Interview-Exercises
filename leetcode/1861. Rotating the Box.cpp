class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Configure
        for (int i = 0; i < m; i++) {
            int right = n - 1;
            while (right >= 0 && boxGrid[i][right] != '.') {
                right--;
            }
            for (int left = right - 1; left >= 0; left--) {
                if (boxGrid[i][left] == '*') {
                    right = left - 1;
                    continue;
                }
                while (right > left && boxGrid[i][right] != '.') {
                    right--;
                }
                if (right < 0) break;
                if (boxGrid[i][left] == '#') {
                    swap(boxGrid[i][left], boxGrid[i][right]);
                }
            }
        }

        // Rotate
        vector<vector<char>> rotated(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][i] = boxGrid[m - i - 1][j];
            }
        }

        return rotated;
    }
};