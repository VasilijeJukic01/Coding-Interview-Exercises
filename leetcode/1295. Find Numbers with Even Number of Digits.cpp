class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int digits = 0;
            while (n) {
                digits++;
                n /= 10;
            }
            if (digits % 2 == 0) result++;
        }

        return result;
    }
};