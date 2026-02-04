class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            dist[u][v] = dist[v][u] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int best = 0;
        int currMin = n;
        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    counter++;
                }
            }

            if (counter <= currMin) {
                currMin = counter;
                best = i;
            }
        }

        return best;
    }
};