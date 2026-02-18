class Solution {
public:
    using p = array<int, 2>;

    vector<int> counts;

    void conquer(vector<p>& arr, int start, int end, int mid) {
        vector<p> left, right;

        for (int i = start; i <= mid; i++) {
            left.push_back(arr[i]);
        }
        for (int i = mid + 1; i <= end; i++) {
            right.push_back(arr[i]);
        }

        int l = 0, r = 0;
        int write = start;
        // How many smaller numbers
        int counter = 0;
        while (l < left.size() && r < right.size()) {
            if (right[r][0] < left[l][0]) {
                counter++;
                arr[write++] = right[r++];
            }
            else {
                // Who
                counts[left[l][1]] += counter;
                arr[write++] = left[l++];
            }
        }

        while (l < left.size()) {
            counts[left[l][1]] += counter;
            arr[write++] = left[l++];
        }

        while (r < right.size()) {
            arr[write++] = right[r++];
        }
    }

    void divide(vector<p>& arr, int start, int end) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;

        divide(arr, start, mid);
        divide(arr, mid + 1, end);
        conquer(arr, start, end, mid); 
    }

    vector<int> countSmaller(vector<int>& nums) {
        counts.resize(nums.size(), 0);

        vector<p> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        divide(arr, 0, arr.size() - 1);

        return counts;
    }
};