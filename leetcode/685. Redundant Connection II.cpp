class union_find {
    vector<int> parent;
    vector<int> rank;
public:
    union_find(int n) {
        rank.resize(n, 0);
        parent.resize(n);
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

        if (rank[rootI] > rank[rootJ]) {
            parent[rootJ] = rootI;
        }
        else if (rank[rootJ] > rank[rootI]) {
            parent[rootI] = rootJ;
        }
        else {
            rank[rootI]++;
            parent[rootJ] = rootI;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> edge1, edge2;
        vector<int> parents(n + 1, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (parents[v] == 0) parents[v] = u;
            else {
                edge1 = {parents[v], v};
                edge2 = e;
            }
        }

        union_find uf(n + 1);
        for (auto& e : edges) {
            if (e == edge2) continue;
            int u = e[0];
            int v = e[1];
            if (!uf.unite(u, v)) {
                if (!edge1.empty()) return edge1;
                return e;
            }
        }

        return edge2;
    }
};