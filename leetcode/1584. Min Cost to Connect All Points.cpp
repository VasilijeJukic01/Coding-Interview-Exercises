class union_find {
private:
    vector<int> parent;
    vector<int> rank;
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dx = abs(points[i][0] - points[j][0]);
                int dy = abs(points[i][1] - points[j][1]);
                edges.push_back({dx + dy, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;
        union_find uf(points.size());

        int counter = 1;
        for (auto& e : edges) {
            if (counter == points.size()) break;
            if (uf.unite(e[1], e[2])) {
                cost += e[0];
                counter++;
            }
        }

        return cost;
    }
};