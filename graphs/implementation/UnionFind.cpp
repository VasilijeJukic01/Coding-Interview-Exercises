/*
* Disjoint Set Union (DSU)
 *
 * Features:
 * - Find with Path Compression: Flattens the structure of the tree.
 * - Union by Rank/Size: Attaches smaller tree to larger tree.
 *
 * Time Complexity: O(alpha(n)) ~ O(1) amortized.
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // Initialize parent[i] = i
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        // Path Compression
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI != rootJ) {
            // Union by Rank
            if (rank[rootI] < rank[rootJ])
                parent[rootI] = rootJ;
            else if (rank[rootI] > rank[rootJ])
                parent[rootJ] = rootI;
            else {
                parent[rootI] = rootJ;
                rank[rootJ]++;
            }
        }
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

int main() {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(1, 2);

    cout << "0 and 2 connected? " << (dsu.connected(0, 2) ? "Yes" : "No") << endl;
    cout << "0 and 4 connected? " << (dsu.connected(0, 4) ? "Yes" : "No") << endl;

    return 0;
}