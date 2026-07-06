class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& x, const vector<int>& y){
                return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
        });

        int total = 1;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= start && intervals[i][1] <= end) {
                continue;
            }
            total++;
            start = intervals[i][0];
            end = intervals[i][1];
        }

        return total;
    }
};