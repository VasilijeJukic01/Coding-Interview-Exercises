class union_find {
private:
    vector<int> rank;
    vector<int> parent;
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
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), []
            (const vector<int>& e1, const vector<int>& e2){
                return e1[2] < e2[2];
        });

        int components = n;
        union_find uf(n);

        int cost = 0;
        for (auto& e : edges) {
            if (components == k) break;
            int u = e[0], v = e[1];
            int w = e[2];

            if (uf.unite(u, v)) {
                components--;
                cost = w;
            }
        }

        return cost;
    }
};