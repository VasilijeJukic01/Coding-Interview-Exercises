class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2 * n, 0);

        for (int i = 0; i < n; i++) {
            v[i] = v[i + n] = nums[i];
        }

        return v;
    }
};