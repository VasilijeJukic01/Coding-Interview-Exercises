class Solution {
public:
    double calculateSlope(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return DBL_MAX;
        return (double)(b[1] - a[1]) / (b[0] - a[0]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int maxPoints = 0;
        for (int i = 0; i < n - 1; i++) {
            // {slope, points that lie in the slope}
            unordered_map<double, int> map;
            auto& a = points[i];
            for (int j = i + 1; j < n; j++) {
                auto& b = points[j];
                double m = calculateSlope(a, b);
                map[m]++;
                maxPoints = max(maxPoints, map[m]);
            }
        }

        return maxPoints + 1;
    }
};