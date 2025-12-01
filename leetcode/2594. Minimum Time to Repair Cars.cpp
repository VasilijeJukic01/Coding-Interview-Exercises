class Solution {
public:
    bool can(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;

        for (int i = 0; i < ranks.size(); i++) {
            totalCars += sqrt(mid / ranks[i]);
        }

        if (totalCars >= cars) return true;
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 0;
        long long end = 100LL * cars * cars;

        long long best = -1;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (can(ranks, cars, mid)) {
                end = mid - 1;
                best = mid;
            }
            else start = mid + 1;
        }

        return best;
    }
};