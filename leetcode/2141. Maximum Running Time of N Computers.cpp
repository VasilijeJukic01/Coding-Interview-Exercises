class Solution {
public:
    bool can(vector<int>& batteries, long n, long long t) {
        long long total = 0;

        for (int i = 0; i < batteries.size(); i++) {
            total += min(t, (long long) batteries[i]);
        }

        if (total / n >= t) return true;
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long start = 0;
        long long end = accumulate(batteries.begin(), batteries.end(), 0LL);

        long long best = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (can(batteries, n, mid)) {
                start = mid + 1;
                best = mid;
            }
            else end = mid - 1;
        }

        return best;
    }
};