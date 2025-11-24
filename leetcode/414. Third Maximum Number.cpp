class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long> v(3, LONG_MIN);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > v[0]) {
                v[2] = v[1];
                v[1] = v[0];
                v[0] = nums[i];
            }
            else if (nums[i] > v[1] && nums[i] != v[0]) {
                v[2] = v[1];
                v[1] = nums[i];
            }
            else if (nums[i] > v[2] && nums[i] != v[0] && nums[i] != v[1]) {
                v[2] = nums[i];
            }
        }

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] == LONG_MIN) return v[0];
        }

        return v[2];
    }
};