/*
* Prim's Algorithm
 *
 * Logic:
 * - Grows the MST from a starting vertex.
 * - At each step, adds the cheapest edge connecting a tree node to a non-tree node.
 * - Uses a Priority Queue.
 *
 * Time Complexity: O(E log V)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// {weight, vertex}
typedef pair<int, int> pii;

int prim(int n, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(n, false);

    // Start from node 0
    pq.push({0, 0});
    int mstWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mstWeight += weight;

        for (auto& edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;
            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }
    return mstWeight;
}

int main() {
    int n = 4;
    vector<vector<pii>> adj(n);

    // 0: (1, 10), (2, 6), (3, 5)
    adj[0] = {{10, 1}, {6, 2}, {5, 3}};
    adj[1] = {{10, 0}, {15, 3}};
    adj[2] = {{6, 0}, {4, 3}};
    adj[3] = {{5, 0}, {15, 1}, {4, 2}};

    cout << "Total MST Weight: " << prim(n, adj) << endl;
    return 0;
}