class Solution {
    using table = vector<vector<int>>;
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        table curr(n + 1, vector<int>(200, false));
        table next(n + 1, vector<int>(200, false));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int open = 0; open < 199; open++) {
                    int cnt = open;
                    if (grid[i][j] == ')') {
                        if (cnt == 0) {
                            curr[j][cnt] = false;
                            continue;
                        }
                        cnt--;
                    }
                    else cnt++;

                    if (i == m - 1 && j == n - 1) {
                        curr[j][open] = cnt == 0;
                        continue;
                    }

                    curr[j][open] = next[j][cnt] || curr[j + 1][cnt];
                }
            }
            next = curr;
        }

        return curr[0][0];
    }
};