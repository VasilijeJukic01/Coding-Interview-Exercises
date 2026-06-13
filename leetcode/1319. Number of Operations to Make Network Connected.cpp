class union_find {
private:
    vector<int> parent;
    vector<int> rank;
public:
    union_find(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return false;

        if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        }
        else if (rank[rootJ] < rank[rootI]) {
            parent[rootJ] = rootI;
        }
        else {
            parent[rootI] = rootJ;
            rank[rootJ]++;
        }

        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        union_find uf(n);

        int components = n;
        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];

            if (uf.unite(u, v)) {
                components--;
            }
        }

        return components - 1;
    }
};