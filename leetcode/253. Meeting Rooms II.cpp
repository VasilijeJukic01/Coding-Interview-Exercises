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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        priority_queue<int, vector<int>, greater<>> pq;

        sort(intervals.begin(), intervals.end(), [](const Interval& u, const Interval& v) {
            return u.start < v.start;
        });

        for (int i = 0; i < intervals.size(); i++) {
            // We can place meeting in some free day
            if (!pq.empty() && pq.top() <= intervals[i].start) pq.pop();
            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};
