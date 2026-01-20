class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& track, char type) {
        int m = heights.size();
        int n = heights[0].size();

        queue<array<int, 2>> q;
        for (int i = 0; i < m; i++) {
            if (type == 'A') {
                q.push({i, n - 1});
                track[i][n - 1] |= 1;
            }
            else {
                q.push({i, 0});
                track[i][0] |= 2;
            } 
        }
        for (int j = 0; j < n; j++) {
            if (type == 'A') {
                q.push({m - 1, j});
                track[m - 1][j] |= 1;
            }
            else {
                q.push({0, j});
                track[0][j] |= 2;
            } 
        }

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            array<int, 2> curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];

            for (int k = 0; k < 4; k++) {
                int nI = i + y[k];
                int nJ = j + x[k];
                if (isSafe(nI, nJ, m, n)) {
                    if (type == 'A' && (track[nI][nJ] & 1) != 0) continue;
                    if (type == 'P' && (track[nI][nJ] & 2) != 0) continue;
                    if (heights[nI][nJ] >= heights[i][j]) {
                        q.push({nI, nJ});
                        if (type == 'A') track[nI][nJ] |= 1;
                        else track[nI][nJ] |= 2;
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> track(m, vector<int>(n, 0));

        bfs(heights, track, 'A');
        bfs(heights, track, 'P');

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (track[i][j] == 3) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};