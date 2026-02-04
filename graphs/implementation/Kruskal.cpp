/*
* Kruskal's Algorithm
 *
 * Logic:
 * - Sort all edges by weight.
 * - Pick smallest edge. If it doesn't form a cycle (checked via DSU), add to MST.
 * - Repeat until V-1 edges are added.
 *
 * Time Complexity: O(E log E) or O(E log V)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) parent[rootI] = rootJ;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);

    int mstWeight = 0;
    int edgesCount = 0;

    for (auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mstWeight += edge.weight;
            edgesCount++;
        }
    }
    return mstWeight;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    int weight = kruskal(n, edges);
    cout << "Total MST Weight: " << weight << endl;
    return 0;
}