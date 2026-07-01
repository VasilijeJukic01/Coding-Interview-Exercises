class Solution {
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    bool can(vector<vector<int>>& dist, int t, int n) {
        if (dist[0][0] - 1 < t) return false;
        
        queue<array<int, 2>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            if (i == n - 1 && j == n - 1) return true;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nI = i + dy[k], nJ = j + dx[k];
                if (!isSafe(nI, nJ, n) || visited[nI][nJ]) continue;
                if (dist[nI][nJ] - 1 >= t) {
                    q.push({nI, nJ});
                    visited[nI][nJ] = true;
                }
            }
        }

        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 0));
        queue<array<int, 2>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 1;
                }
            }
        }

        int step = 2;
        while (!q.empty()) {
            int size = q.size();
            for (int p = 0; p < size; p++) {
                auto [i, j] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nI = i + dy[k], nJ = j + dx[k];
                    if (isSafe(nI, nJ, n) && dist[nI][nJ] == 0) {
                        q.push({nI, nJ});
                        dist[nI][nJ] = step;
                    }
                }
            }
            step++;
        }

        int best = 0;
        int start = 0, end = step;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (can(dist, mid, n)) {
                start = mid + 1;
                best = mid;
            }
            else end = mid - 1;
        }

        return best;
    }
};