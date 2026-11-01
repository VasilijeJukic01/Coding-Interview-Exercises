class Solution {
    using p2 = array<int, 2>;
    using p4 = array<int, 4>;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<p2>> adjList(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            int w = e[2];
            adjList[u].push_back({v, w});
        }

        // {currW, u, prev, cnt}
        priority_queue<p4, vector<p4>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        pq.push({0, 0, labels[0], 1});
        for (int cnt = 0; cnt <= k; cnt++) {
            dist[0][cnt] = 0;
        }

        while (!pq.empty()) {
            auto [currW, u, prev, cnt] = pq.top();
            pq.pop();
            if (currW > dist[u][cnt]) continue;

            for (auto& [v, w] : adjList[u]) {
                int cntP = cnt;
                int prevP = prev;
                if (labels[v] == prev) {
                    if (cnt + 1 > k) continue;
                    else cntP++;
                }
                else {
                    prevP = labels[v];
                    cntP = 1;
                }

                if (currW + w < dist[v][cntP]) {
                    dist[v][cntP] = currW + w;
                    pq.push({currW + w, v, prevP, cntP});
                }
            }
        }

        int best = INT_MAX;
        for (int i = 0; i <= k; i++) {
            best = min(best, dist[n - 1][i]);
        }

        return best == INT_MAX ? -1 : best;
    }
};