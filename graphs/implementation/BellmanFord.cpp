/*
* Bellman-Ford Algorithm
 *
 * Logic:
 * - Relaxes all edges V-1 times.
 * - If an edge can still be relaxed after V-1 iterations, there is a negative weight cycle.
 *
 * Time Complexity: O(V * E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, vector<Edge>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source:\n";
    for (int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX) cout << i << ": INF\n";
        else cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(n, edges, 0);
    return 0;
}