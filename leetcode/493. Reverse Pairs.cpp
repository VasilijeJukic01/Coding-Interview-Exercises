class Solution {
public:
    void conquer(vector<int>& nums, int start, int end, int mid, int& cnt) {
        vector<int> left, right;

        for (int i = start; i <= mid; i++) {
            left.push_back(nums[i]);
        }
        for (int i = mid + 1; i <= end; i++) {
            right.push_back(nums[i]);
        }

        // Count
        int l = 0, r = 0;
        while (l < left.size() && r < right.size()) {
            long long p = 2LL * right[r];

            if (left[l] > p) {
                r++;
                cnt += (left.size() - l);
            }
            else l++;
        }

        // Sort
        l = 0, r = 0;
        int write = start;
        while (l < left.size() && r < right.size()) {
            if (left[l] < right[r]) {
                nums[write++] = left[l++];
            }
            else nums[write++] = right[r++];
        }

        while (l < left.size()) {
            nums[write++] = left[l++];
        }
        while (r < right.size()) {
            nums[write++] = right[r++];
        }
    }

    void divide(vector<int>& nums, int start, int end, int& cnt) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        divide(nums, start, mid, cnt);
        divide(nums, mid + 1, end, cnt);
        conquer(nums, start, end, mid, cnt);
    }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        divide(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};