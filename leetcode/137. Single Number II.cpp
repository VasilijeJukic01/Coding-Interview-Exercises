class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;

        for (int k = 0; k < 32; k++) {
            int activeBits = 0;
            for (int i = 0; i < nums.size(); i++) {
                if ((nums[i] >> k) & 1) activeBits++;
            }
            if (activeBits % 3 != 0) {
                x |= (1 << k);
            }
        }

        return x;
    }
};