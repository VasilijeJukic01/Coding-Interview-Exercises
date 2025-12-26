class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int> &p1, const vector<int> &p2) {
            double d1 = sqrt(p1[0] * p1[0] + p1[1] * p1[1]);
            double d2 = sqrt(p2[0] * p2[0] + p2[1] * p2[1]);

            return d1 < d2;
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < points.size(); i++) {
            pq.push(points[i]);

            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};