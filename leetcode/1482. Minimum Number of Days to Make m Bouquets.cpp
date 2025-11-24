class Solution {
public:
    bool can(vector<int> bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int adjFlowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) adjFlowers++;
            else adjFlowers = 0;

            if (adjFlowers == k) {
                bouquets++;
                adjFlowers = 0;
            }
        }

        if (bouquets >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end;

        for (int i = 0; i < bloomDay.size(); i++) {
            end = max(end, bloomDay[i]);
        }

        int best = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (can(bloomDay, m, k, mid)) {
                end = mid - 1;
                best = mid;
            }
            else start = mid + 1;
        }

        return best;
    }
};