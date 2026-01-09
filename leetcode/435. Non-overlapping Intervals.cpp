class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] 
            (const vector<int>& u, const vector<int>& v){
                return u[1] < v[1];
        });

        int total = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            else total++;
        }

        return total;
    }
};