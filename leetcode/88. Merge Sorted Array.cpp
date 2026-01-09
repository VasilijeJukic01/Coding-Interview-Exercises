class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = 0;
        int p1 = 0, p2 = 0;

        vector<int> left = nums1;

        while (p1 < m && p2 < n) {
            if (left[p1] <= nums2[p2]) {
                nums1[index++] = left[p1++];
            }
            else nums1[index++] = nums2[p2++];
        }

        while (p1 < m) {
            nums1[index++] = left[p1++];
        }
        while (p2 < n) {
            nums1[index++] = nums2[p2++];
        }
    }
};