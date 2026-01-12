class Solution {
public:
    bool can(vector<int> piles, int mid, int h) {
        if (mid == 0) return false;
        int totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += (piles[i] / mid) + (piles[i] % mid != 0);
        }

        if (totalHours > h) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 0, end = 0;
        int save = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > end) end = piles[i];
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (can(piles, mid, h)) {
                save = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return save;
    }
};