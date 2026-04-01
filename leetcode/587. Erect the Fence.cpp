class Solution {
public:
    int crossProduct(vector<int> a, vector<int> b, vector<int> c) {
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        int x3 = c[0], y3 = c[1];

        return (y3-y2) * (x2-x1) - (y2-y1) * (x3-x2);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), [] (auto a, auto b) { 
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; 
            }
        );

        vector<vector<int>> lower, upper;

        for (vector<int> point : trees) {
            // Lower Convex Hull
            while (lower.size() >= 2 && crossProduct(lower[lower.size()-2], lower.back(), point) < 0) {
                lower.pop_back();
            }
            // Upper Convex Hull
            while (upper.size() >= 2 && crossProduct(upper[upper.size()-2], upper.back(), point) > 0) {
                upper.pop_back();
            }

            lower.push_back(point);
            upper.push_back(point);
        }

        set<vector<int>> hullSet;
        for (auto point : lower) {
            hullSet.insert(point);
        }
        for (auto point : upper) {
            hullSet.insert(point);
        }

        vector<vector<int>> result(hullSet.begin(), hullSet.end());
        return result;
    }
};