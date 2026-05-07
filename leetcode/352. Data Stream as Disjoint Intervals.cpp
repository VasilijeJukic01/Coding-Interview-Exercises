class union_find {
    vector<int> parent;
    vector<int> rank;
public:
    set<int> roots;
    vector<int> minVal, maxVal;

    union_find(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        minVal.resize(n);
        maxVal.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            minVal[i] = i;
            maxVal[i] = i;
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

        int parentRoot, childRoot;
        if (rank[rootI] < rank[rootJ]) {
            parentRoot = rootJ;
            childRoot = rootI;
        }
        else if (rank[rootJ] < rank[rootI]) {
            parentRoot = rootI;
            childRoot = rootJ;
        }
        else {
            parentRoot = rootI;
            childRoot = rootJ;
            rank[rootJ]++;
        }

        parent[childRoot] = parentRoot;
        roots.erase(childRoot);
        minVal[parentRoot] = min(minVal[parentRoot], minVal[childRoot]);
        maxVal[parentRoot] = max(maxVal[parentRoot], maxVal[childRoot]);

        return true;
    }
};

class SummaryRanges {
    union_find uf;
    vector<bool> seen;
public:
    SummaryRanges() : uf(10005), seen(10005, false) {}
    
    void addNum(int value) {
        if (seen[value]) return;
        
        seen[value] = true;
        uf.roots.insert(value);
        
        if (value > 0 && seen[value - 1]) {
            uf.unite(value, value - 1);
        }
        if (value < 10000 && seen[value + 1]) {
            uf.unite(value, value + 1);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto& root : uf.roots) {
            result.push_back({uf.minVal[root], uf.maxVal[root]});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */