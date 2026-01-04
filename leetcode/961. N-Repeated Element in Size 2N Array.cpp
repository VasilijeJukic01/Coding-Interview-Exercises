class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m = nums.size();
        
        int first = nums[0];
        int second = nums[1];
        for (int i = 2; i < m; i++) {
            int third = nums[i];
            if (third == first || third == second) return third;
            
            first = second;
            second = third;
        }

        return second;
    }
};