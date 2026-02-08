class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.rbegin(), nums1.rend());

        vector<array<int, 2>> sortedNums2;
        for (int i = 0; i < nums2.size(); i++) {
            sortedNums2.push_back({nums2[i], i});
        }
        sort(sortedNums2.rbegin(), sortedNums2.rend());

        vector<int> result(nums1.size(), 0);

        int left = 0, right = nums1.size() - 1;
        int ptr = 0;
        while (left <= right) {
            if (nums1[left] > sortedNums2[ptr][0]) {
                result[sortedNums2[ptr][1]] = nums1[left];
                left++;
            }
            else {
                result[sortedNums2[ptr][1]] = nums1[right];
                right--;
            }
            ptr++;
        }

        return result;
    }
};