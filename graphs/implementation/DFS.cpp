/*
* Depth-First Search (DFS)
 *
 * Logic:
 * - Explores as far as possible along each branch before backtracking.
 * - Uses Recursion (System Stack) or an explicit Stack.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, adj, visited);
        }
    }
}

void dfs(int startNode, int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    dfsUtil(startNode, adj, visited);
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

    dfs(0, n, adj);

    return 0;
}