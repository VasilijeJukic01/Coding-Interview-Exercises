class Solution {
public:
    int findMajority(vector<int>& nums, int start, int end, int l, int r) {
        int leftC = 0, rightC = 0;

        int n = (end - start + 1) / 2;
        for (int i = start; i <= end; i++) {
            if (nums[i] == l) leftC++;
            else if (nums[i] == r) rightC++;

            if (leftC > n) return l;
            if (rightC > n) return r;
        }

        return 0;
    }

    int divideAndConquer(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];

        int mid = start + (end - start) / 2;

        int lMajority = divideAndConquer(nums, start, mid);
        int rMajority = divideAndConquer(nums, mid + 1, end);
        if (lMajority == rMajority) return lMajority;

        return findMajority(nums, start, end, lMajority, rMajority);
    }

    int majorityElement(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }
};