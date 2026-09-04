class Solution {
public:
    bool findSmaller(int x, vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] < x) return true;
            else end = mid - 1;
        }
        return false;
    }

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        vector<int> odd;
        sort(nums1.begin(), nums1.end());

        for (int i = 0; i < n; i++) {
            if (nums1[i] & 1) odd.push_back(nums1[i]);
        }

        // Even check
        bool evenCheck = true;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 != 0) {
                if (!findSmaller(nums1[i], odd)) {
                    evenCheck = false;
                    break;
                }
            } 
        }

        if (evenCheck) return true;

        // Odd check
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                if (!findSmaller(nums1[i], odd)) return false;
            } 
        }

        return true;
    }
};