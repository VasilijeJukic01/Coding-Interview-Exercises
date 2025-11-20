class Solution {
public:
	// Asc by second, Desc by first
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] > b[0];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int total = 0;

        sort(intervals.begin(), intervals.end(), compare);
        int rightMost = -1, secondRightMost = -1;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start > rightMost) {
                rightMost = end;
                secondRightMost = end - 1;
                total += 2;
            }
            else if (start > secondRightMost) {
                secondRightMost = rightMost;
                rightMost = end;
                total += 1;
            }
        }

        return total;
    }
};