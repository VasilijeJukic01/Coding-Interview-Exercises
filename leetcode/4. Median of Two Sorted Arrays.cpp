class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int> &smaller = (m < n) ? nums1 : nums2;
        vector<int> &bigger  = (m < n) ? nums2 : nums1;

        int start = 0, end = smaller.size();
        int left1, right1;
        int left2, right2;
        while (start <= end) {
            // Should take i + j = (totalElements + 1) / 2
            // Number of elements from smaller array
            int i = start + (end - start) / 2;
            // Number of elements from bigger array
            int j = (m + n + 1) / 2 - i;

            if (i - 1 < 0) left1 = INT_MIN;
            else left1 = smaller[i - 1];
            
            if (i >= smaller.size()) right1 = INT_MAX;
            else right1 = smaller[i];

            if (j - 1 < 0) left2 = INT_MIN;
            else left2 = bigger[j - 1];

            if (j >= bigger.size()) right2 = INT_MAX;
            else right2 = bigger[j];

            if (left1 <= right2 && left2 <= right1) break;
            if (left1 > right2) end = i - 1; // We take too many from nums1
            else start = i + 1; // We take too many from nums2
        }

        if ((m + n) % 2 == 0) {
            return (max(left1, left2) + min(right1, right2)) / 2.0;
        }
        return max(left1, left2);
    }
};