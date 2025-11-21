class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> v;
        sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});

        int collected = 1;
        v.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (collected == k) break;
            if (nums[i] != v.back()) {
                v.push_back(nums[i]);
                collected++;
            }
        }

        return v;
    }
};