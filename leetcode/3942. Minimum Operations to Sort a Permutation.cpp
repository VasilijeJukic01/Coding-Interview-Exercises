class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int incrDrops = 0, decrDrops = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (nums[i] < nums[next]) decrDrops++;
            else incrDrops++;
        }

        if (incrDrops == 0) return 0;
        // Need to reverse
        if (decrDrops == 0) return 1;

        if (incrDrops > 1 && decrDrops > 1) return -1;
        if (decrDrops > 1 && incrDrops > 1) return -1;

        int p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                p = i;
                break;
            }
        }

        // Increasing array
        if (incrDrops == 1) return min(p, n - p + 2);
        // Decreasing array
        else return min(n - p, p + 2);
    }
};