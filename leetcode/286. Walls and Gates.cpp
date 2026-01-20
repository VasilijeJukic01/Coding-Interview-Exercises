#include <array>

class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        queue<array<int, 2>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                array<int, 2> curr = q.front();
                q.pop();
                int i = curr[0];
                int j = curr[1];

                for (int l = 0; l < 4; l++) {
                    int nI = i + y[l];
                    int nJ = j + x[l];
                    if (isSafe(nI, nJ, m, n) && grid[nI][nJ] == 2147483647) {
                        q.push({nI, nJ});
                        grid[nI][nJ] = step;
                    }
                }
            }
            step++;
        }
    }
};
