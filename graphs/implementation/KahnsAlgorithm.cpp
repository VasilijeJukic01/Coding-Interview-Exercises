/*
* Kahn's Algorithm (Topological Sort)
 *
 * Logic:
 * - Computes in-degrees of all nodes.
 * - Adds nodes with 0 in-degree to a queue.
 * - Removes nodes from queue, reduces neighbors' in-degree.
 * - If in-degree becomes 0, add neighbor to queue.
 * - If count of visited nodes < N, graph has a cycle.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnsAlgorithm(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Cycle detection
    if (topoOrder.size() != n) return {};
    return topoOrder;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    // 5 -> 0, 5 -> 2, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = kahnsAlgorithm(n, adj);

    if (result.empty()) cout << "Cycle detected!";
    else {
        cout << "Topological Sort: ";
        for (int x : result) cout << x << " ";
    }
    cout << endl;

    return 0;
}