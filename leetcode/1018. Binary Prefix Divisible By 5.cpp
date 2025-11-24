class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;

        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr << 1 | nums[i]) % 5;
            result.push_back(curr == 0);
        }

        return result;
    }
};