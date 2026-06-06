class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int leftSum = 0, rightSum = 0;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            left[i] += leftSum;
            right[j] += rightSum;
            leftSum += nums[i];
            rightSum += nums[j];
        }

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = abs(left[i] - right[i]);
        }

        return result;
    }
};