class Solution {
    using ll = long long;
public:
    void conquer(vector<int> &pSum, int start, int end, int mid, ll &total) {
        vector<int> left, right;
        for (int i = start; i <= mid; i++) {
            left.push_back(pSum[i]);
        }
        for (int i = mid + 1; i <= end; i++) {
            right.push_back(pSum[i]);
        }

        // Count
        int l = 0, r = 0;
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                total += right.size() - r;
                l++;
            }
            else r++;
        }

        // Sort
        l = 0, r = 0;
        int write = start;
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                pSum[write++] = left[l++];
            }
            else pSum[write++] = right[r++];
        }

        while (l < left.size()) {
            pSum[write++] = left[l++];
        }
        while (r < right.size()) {
            pSum[write++] = right[r++];
        }
    }

    void solve(vector<int> &pSum, int start, int end, ll &total) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        solve(pSum, start, mid, total);
        solve(pSum, mid + 1, end, total);
        conquer(pSum, start, end, mid, total);
    }

    ll countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] == target ? 1 : -1;
        }

        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + nums[i];
        }

        ll total = 0;
        solve(pSum, 0, n, total);
        return total;
    }
};