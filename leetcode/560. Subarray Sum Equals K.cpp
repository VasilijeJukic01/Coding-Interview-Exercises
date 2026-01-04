class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;

        int prefixSum = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if (map[prefixSum - k]) total += map[prefixSum - k];
            map[prefixSum]++;
        }

        return total;
    }
};