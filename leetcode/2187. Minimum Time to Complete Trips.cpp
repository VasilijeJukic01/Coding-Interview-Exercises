class Solution {
public:
    bool can(vector<int> time, int totalTrips, long long t) {
        long long total = 0;

        for (int i = 0; i < time.size(); i++) {
            long long trips = t / time[i];
            if (trips > totalTrips) return true;
            total += trips;
        }

        if (total >= totalTrips) return true;
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 0;
        long long end = LONG_MAX;

        long long best = -1;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (can(time, totalTrips, mid)) {
                end = mid - 1;
                best = mid;
            }
            else start = mid + 1;
        }

        return best;
    }
};