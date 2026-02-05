class union_find {
private:
    vector<int> rank;
    vector<int> parent;
public:
    
    union_find(int n) {
        rank.resize(n);
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
        }
        else if (rank[parentJ] < rank[parentI]) {
            parent[parentJ] = parentI;
        }
        else {
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }
        
        return true;
    }
};


class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int solve(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        union_find uf(m * n);
        int islands = 0;
        for (auto& p : positions) {
            int i = p[0], j = p[1];
            if (grid[i][j] == 1) continue;
            
            grid[i][j] = 1;
            islands++;
            
            int merged = 0;
            for (int k = 0; k < 4; k++) {
                int nI = i + dy[k];
                int nJ = j + dx[k];
                
                if (isSafe(nI, nJ, m, n) && grid[nI][nJ] == 1) {
                    int u = i * n + j;
                    int v = nI * n + nJ;
                    if (uf.unite(u, v)) merged++;
                }
            }
            
            if (merged > 0) islands -= merged;
        }
        
        return islands;
    }
};