class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // {sum, bound}
        unordered_map<int, int> suffSums;
        suffSums[0] = n;

        int curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr += nums[i];
            if (!suffSums.count(curr)) {
                suffSums[curr] = i;
            }
        }

        curr = 0;
        int best = INT_MAX;
        if (suffSums.count(x)) best = n - suffSums[x];

        for (int i = 0; i < n; i++) {
            curr += nums[i];
            if (suffSums.count(x - curr)) {
                int bound = suffSums[x - curr];
                if (i >= bound) continue;
                best = min(best, i + 1 + (n - bound));
            }
        }

        if (best == INT_MAX) return -1;
        return best;
    }
};