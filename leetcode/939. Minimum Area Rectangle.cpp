class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> s;

        for (auto& p : points) {
            s.insert(p[0] * 40001 + p[1]); 
        }

        int minArea = INT_MAX;
        for (int i = 0; i < points.size() - 1; i++) {
            auto& a = points[i];
            for (int j = i + 1; j < points.size(); j++) {
                auto& b = points[j];
                if (a[0] == b[0] || a[1] == b[1]) continue;

                int key1 = a[0] * 40001 + b[1];
                int key2 = b[0] * 40001 + a[1];
                if (s.find(key1) == s.end() || s.find(key2) == s.end()) {
                    continue;
                }

                int wid = abs(a[0] - b[0]);
                int hei = abs(a[1] - b[1]);
                minArea = min(minArea, wid * hei);
            }
        }

        if (minArea == INT_MAX) return 0;
        return minArea;
    }
};