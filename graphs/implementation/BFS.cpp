/*
* Breadth-First Search (BFS)
 *
 * Logic:
 * - Explores the graph layer by layer.
 * - Uses a Queue data structure.
 * - Essential for finding the shortest path in an unweighted graph.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int startNode, int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    // Edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    bfs(0, n, adj);

    return 0;
}