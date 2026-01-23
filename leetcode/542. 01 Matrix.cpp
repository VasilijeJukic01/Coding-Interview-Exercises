class Solution {
public:
    using p = array<int, 2>;

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<p> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};

        int d = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [i, j] = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nI = i + y[dir];
                    int nJ = j + x[dir];
                    
                    if (isSafe(nI, nJ, m, n) && mat[nI][nJ] == 1) {
                        if (dist[nI][nJ] != INT_MAX) continue;
                        dist[nI][nJ] = d;
                        q.push({nI, nJ});
                    }
                }
            }
            d++;
        }

        return dist;
    }
};