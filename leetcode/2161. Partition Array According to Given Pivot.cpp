class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int write = 0;
        vector<int> result(n);

        // Less
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) result[write++] = nums[i];
        }
        // Equal
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) result[write++] = nums[i];
        }
        // Greater
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) result[write++] = nums[i];
        }

        return result;
    }
};