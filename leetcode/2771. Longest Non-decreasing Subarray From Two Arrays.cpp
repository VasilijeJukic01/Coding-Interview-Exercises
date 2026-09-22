class Solution {
    const int ARR1 = 0, ARR2 = 1, NOT_STARTED = 2;
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        array<int, 3> curr = {0, 0, 0}, next = {0, 0, 0};
        for (int i = n - 1; i >= 0; i--) {
            for (int prevArr = 0; prevArr <= 2; prevArr++) {
                int prev = 0;
                if (i > 0) {
                    prev = prevArr == 0 ? nums1[i - 1] : nums2[i - 1];
                }
                if (prevArr != NOT_STARTED) {
                    int take1 = 0, take2 = 0;
                    if (nums1[i] >= prev) take1 = 1 + next[ARR1];
                    if (nums2[i] >= prev) take2 = 1 + next[ARR2];

                    curr[prevArr] = max(take1, take2);
                }
                else {
                    int skip = next[NOT_STARTED];
                    int start1 = 1 + next[ARR1];
                    int start2 = 1 + next[ARR2];

                    curr[prevArr] = max({skip, start1, start2});
                }
            }
            next = curr;
        }

        return curr[NOT_STARTED];
    }
};