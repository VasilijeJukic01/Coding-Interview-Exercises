class union_find {
private:
    vector<int> parent;
    vector<int> rank;
public:
    vector<int> nodeCount, edgeCount;

    union_find(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        nodeCount.resize(n, 1);
        edgeCount.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) {
            edgeCount[rootI]++;
            return;
        }

        if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
            nodeCount[rootJ] += nodeCount[rootI];
            edgeCount[rootJ] += (edgeCount[rootI] + 1);
        }
        else if (rank[rootJ] < rank[rootI]) {
            parent[rootJ] = rootI;
            nodeCount[rootI] += nodeCount[rootJ];
            edgeCount[rootI] += (edgeCount[rootJ] + 1);
        }
        else {
            parent[rootI] = rootJ;
            nodeCount[rootJ] += nodeCount[rootI];
            edgeCount[rootJ] += (edgeCount[rootI] + 1);
            rank[rootJ]++;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        union_find uf(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            uf.unite(u, v);
        }

        // Complete graph -> e = v(v-1)/2
        unordered_set<int> seen;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);

            if (seen.count(root)) continue;
            seen.insert(root);

            int V = uf.nodeCount[root];
            int E = uf.edgeCount[root];
            if (E == V * (V - 1) / 2) total++;
        }

        return total;
    }
};