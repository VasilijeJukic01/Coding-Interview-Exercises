class Solution {
public:
    // {weight, destination}
    using p = array<int, 2>;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adjList(n + 1);
        
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adjList[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<p, vector<p>, greater<>> pq;

        pq.push({0, k});
        dist[k] = 0;

        // Dijkstra
        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor[0];
                int w = neighbor[1];
                if (currDist + w < dist[v]) {
                    dist[v] = currDist + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int delay = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            delay = max(delay, dist[i]);
        }

        return delay;
    }
};