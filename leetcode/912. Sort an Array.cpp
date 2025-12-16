class Solution {
public:
int partition(vector<int>& nums, int start, int end) {
        int rIndex = start + rand() % (end - start + 1);
        swap(nums[rIndex], nums[end]);

        int pivot = nums[end];
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if (nums[i] < pivot) swap(nums[i], nums[pIndex++]);
        }
        swap(nums[pIndex], nums[end]);

        return pIndex;
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if (start >= end) return;

        int pIndex = partition(nums, start, end);
        quickSort(nums, start, pIndex - 1);
        quickSort(nums, pIndex + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};