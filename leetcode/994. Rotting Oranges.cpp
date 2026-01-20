class Solution {
public:
    bool isSafe(int m, int n, int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        queue<array<int, 2>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (q.empty() && fresh == 0) return 0;

        int time = -1;
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
                    if (isSafe(m, n, nI, nJ) && grid[nI][nJ] == 1) {
                        q.push({nI, nJ});
                        grid[nI][nJ] = 0;
                        fresh--;
                    }
                }
            }
            time++;
        }

        if (fresh == 0) return time;
        return -1;
    }
};