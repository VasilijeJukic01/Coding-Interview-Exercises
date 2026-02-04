/*
* Floyd-Warshall Algorithm
 *
 * Logic:
 * - Dynamic Programming approach.
 * - Considers every vertex as an intermediate node.
 * - dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 *
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000L

using namespace std;

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(n, graph);
    return 0;
}