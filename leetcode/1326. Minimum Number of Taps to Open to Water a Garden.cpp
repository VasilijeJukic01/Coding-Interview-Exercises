class Solution {
public:
    using p = array<int, 2>;

    int minTaps(int n, vector<int>& ranges) {
        vector<p> intervals;
        for (int i = 0; i < ranges.size(); i++) {
            p interval = {max(0, i - ranges[i]), min(n, i + ranges[i])};
            intervals.push_back(interval);
        }

        vector<int> reach(n + 1, 0);
        for (auto& interval : intervals) {
            reach[interval[0]] = max(reach[interval[0]], interval[1]);
        }

        int taps = 0;
        int left = 0, right = 0;
        while (right < n) {
            int maxReach = right;
            for (int k = left; k <= right; k++) {
                maxReach = max(maxReach, reach[k]);
            }
            if (maxReach <= right) return -1;

            left = right;
            right = maxReach;
            taps++;
        }

        return taps;
    }
};