class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int sum = 0;
            for(; n ; n /= 10) {
                sum += n % 10;
            }
            if (sum == i) return i;
        }

        return - 1;
    }
};