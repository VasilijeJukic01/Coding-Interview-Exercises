class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    bool can(vector<vector<int>>& grid, int t) {
        int n = grid.size();

        if (grid[0][0] > t) return false;

        queue<array<int, 2>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + dy[k];
                int nJ = j + dx[k];
                if (isSafe(nI, nJ, n) && !visited[nI][nJ]) {
                    if (grid[nI][nJ] > t) continue;
                    if (nI == n - 1 && nJ == n - 1) return true;
                    q.push({nI, nJ});
                    visited[nI][nJ] = true;
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int start = 0, end = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                end = max(end, grid[i][j]);
            }
        }

        int best = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (can(grid, mid)) {
                best = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        return best;
    }
};