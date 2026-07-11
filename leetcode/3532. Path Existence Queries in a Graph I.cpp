class union_find {
    vector<int> parent;
    vector<int> rank;
public:
    union_find(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            }
            else if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            }
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

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        union_find uf(n);
        for (int u = 0; u < n - 1; u++) {
            if (abs(nums[u] - nums[u + 1]) > maxDiff) continue;
            uf.unite(u, u + 1);
        }

        vector<bool> result;
        for (auto& q : queries) {
            result.push_back(uf.connected(q[0], q[1]));
        }

        return result;
    }
};