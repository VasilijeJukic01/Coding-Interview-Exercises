class Solution {
public:
    // {effort, i, j}
    using t = array<int, 3>;

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<t, vector<t>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1}; 

        while (!pq.empty()) {
            auto [currCost, i, j] = pq.top();
            pq.pop();

            if (currCost > dist[i][j]) continue;

            for (int k = 0; k < 4; k++) {
                int nI = i + dy[k];
                int nJ = j + dx[k];
                if (!isSafe(nI, nJ, m, n)) continue;

                int effort = abs(heights[i][j] - heights[nI][nJ]);
                if (max(currCost, effort) < dist[nI][nJ]) {
                    dist[nI][nJ] = max(currCost, effort);
                    pq.push({dist[nI][nJ], nI, nJ});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};