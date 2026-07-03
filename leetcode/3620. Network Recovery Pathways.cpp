class Solution {
    using ll = long long;
    using p = array<ll, 2>;

    bool can(vector<vector<p>>& adjList, int mid, ll k) {
        int n = adjList.size();
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<p, vector<p>, greater<>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [currCost, u] = pq.top();
            pq.pop();

            if (dist[u] < currCost) continue;

            for (auto& [v, w] : adjList[u]) {
                if (w < mid) continue;
                if (currCost + w < dist[v]) {
                    pq.push({currCost + w, v});
                    dist[v] = currCost + w;
                }
            }
        }

        if (dist[n - 1] > k) return false;
        return true;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, ll k) {
        ll maxWeight = 0;

        vector<vector<p>> adjList(online.size());
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (!online[u] || !online[v]) continue;
            int w = e[2];
            adjList[u].push_back({v, w});
            maxWeight = max(maxWeight, (ll)w);
        }

        int score = -1;
        int start = 0, end = maxWeight;
        while (start <= end) {
            // mid = score
            ll mid = start + (end - start) / 2;

            if (can(adjList, mid, k)) {
                score = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }

        return score;
    }
};