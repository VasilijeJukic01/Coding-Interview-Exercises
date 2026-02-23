/*
 * Edmonds-Karp Algorithm for Max Flow
 * Time Complexity: O(V * E^2)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    n = 6;
    capacity.assign(n, vector<int>(n, 0));
    adj.resize(n);

    // Helper to add edges
    auto add_edge = [&](int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = cap;
    };

    add_edge(0, 1, 16); add_edge(0, 2, 13);
    add_edge(1, 2, 10); add_edge(1, 3, 12);
    add_edge(2, 1, 4);  add_edge(2, 4, 14);
    add_edge(3, 2, 9);  add_edge(3, 5, 20);
    add_edge(4, 3, 7);  add_edge(4, 5, 4);

    cout << "Max Flow: " << max_flow(0, 5) << endl;
    return 0;
}