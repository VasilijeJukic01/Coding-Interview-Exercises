/*
* Dijkstra's Algorithm
 *
 * Logic:
 * - Greedy approach using a Priority Queue (Min-Heap).
 * - Always expands the nearest unvisited node.
 * - Does NOT work with negative edge weights.
 *
 * Time Complexity: O(E log V)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// {weight, node}
typedef pair<int, int> pii;

vector<int> dijkstra(int n, vector<vector<pii>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);

    // 0 -> 1 (w=4), 0 -> 2 (w=1)
    adj[0].push_back({4, 1});
    adj[0].push_back({1, 2});

    // 2 -> 1 (w=2), 2 -> 3 (w=5)
    adj[2].push_back({2, 1});
    adj[2].push_back({5, 3});

    // 1 -> 3 (w=1)
    adj[1].push_back({1, 3});

    vector<int> distances = dijkstra(n, adj, 0);

    cout << "Shortest paths from Node 0:\n";
    for (int i = 0; i < n; i++) {
        if(distances[i] == INT_MAX) cout << i << ": INF\n";
        else cout << i << ": " << distances[i] << "\n";
    }

    return 0;
}