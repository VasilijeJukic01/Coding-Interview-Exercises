/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        
        sort(intervals.begin(), intervals.end(), [] 
            (const Interval& u, const Interval& v) {
                return u.end < v.end;
        });

        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < end) return false;
            end = intervals[i].end;
        }

        return true;
    }
};
