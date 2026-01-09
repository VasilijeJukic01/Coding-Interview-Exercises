class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size(), 0);

        int left = 0;
        int right = nums.size() - 1;
        int index = right;

        for (int i = 0; i < nums.size(); i++) {
            int leftSide = nums[left] * nums[left];
            int rightSide = nums[right] * nums[right];
            if (leftSide > rightSide) {
                v[index] = leftSide;
                left++;
            }
            else {
                v[index] = rightSide;
                right--;
            }
            index--;
        }

        return v;
    }
};