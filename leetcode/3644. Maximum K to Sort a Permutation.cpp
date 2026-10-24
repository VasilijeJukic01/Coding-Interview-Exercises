class Solution {
    const int INF = (1 << 30) - 1;
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int k = INF;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) k &= nums[i];
        }

        return k == INF ? 0 : k;
    }
};