class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;

        long long currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (map.count(currSum % k) && i - map[currSum % k] >= 2) {
                return true;
            }
            else if (map.count(currSum % k) == 0) map[currSum % k] = i;
        }

        return false;
    }
};