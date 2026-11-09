class union_find {
private:
    vector<int> rank;
    vector<int> parent;
public:
    vector<int> groupSize;

    union_find(int n) {
        rank.resize(n, 0);
        groupSize.resize(n, 1);
        parent.resize(n);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int i) {
        if (parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }
    
    bool unite(int i, int j) {
        int parentI = find(i);
        int parentJ = find(j);
        
        if (parentI == parentJ) return false;
        
        if (rank[parentI] < rank[parentJ]) {
            parent[parentI] = parentJ;
            groupSize[parentJ] += groupSize[parentI];
        }
        else if (rank[parentJ] < rank[parentI]) {
            parent[parentJ] = parentI;
            groupSize[parentI] += groupSize[parentJ];
        }
        else {
            parent[parentI] = parentJ;
            groupSize[parentJ] += groupSize[parentI];
            rank[parentJ]++;
        }
        
        return true;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        union_find uf(m * n);
        for (int i = 0; i < m; i++) {
            int prev = -1;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int x = i * n + j;
                if (prev != -1) {
                    uf.unite(prev, x);
                }
                prev = x;
            }
        }

        for (int j = 0; j < n; j++) {
            int prev = -1;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) continue;
                int x = i * n + j;
                if (prev != -1) {
                    uf.unite(prev, x);
                }
                prev = x;
            }
        }

        int total = 0;
        vector<bool> visited(m * n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int root = uf.find(i * n + j);
                if (visited[root]) continue;
                visited[root] = true;

                int size = uf.groupSize[root];
                if (size > 1) total += size;
            }
        }

        return total;
    }
};