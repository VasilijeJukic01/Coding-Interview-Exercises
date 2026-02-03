class union_find {
public:
    vector<int> parent;
    vector<int> rank;

    union_find(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i, int j) {
        int parentI = find(i);
        int parentJ = find(j);

        if (parentI == parentJ) return;
        if (rank[parentI] < rank[parentJ]) {
            parent[parentI] = parentJ;
        }
        else if (rank[parentJ] < rank[parentI]) {
            parent[parentJ] = parentI;
        }
        else {
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        union_find uf(n);

        for (auto& e : edges) {
            if (uf.connected(e[0], e[1])) return e;
            uf.unite(e[0], e[1]);
        }

        return {};
    }
};