class union_find {
    vector<int> rank;
    vector<int> parent;
public:
    union_find(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < parent.size(); i++) {
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
            parent[rootI] = parent[rootJ];
        }
        else if (rank[rootJ] < rank[rootI]) {
            parent[rootJ] = parent[rootI];
        }
        else {
            parent[rootI] = parent[rootJ];
            rank[rootJ]++;
        }

        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        union_find uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isConnected[i][j]) {
                    uf.unite(i, j);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(uf.find(i));
        }

        return s.size();
    }
};