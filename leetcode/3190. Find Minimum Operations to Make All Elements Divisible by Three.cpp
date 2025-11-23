class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int k = 0; k < 3; k++) {
                int mod = nums[i] % 3;
                if ((mod + k) % 3 == 0 || abs(mod - k) % 3 == 0) {
                    total += k;
                    break;
                }
            }
        }

        return total;
    }
};