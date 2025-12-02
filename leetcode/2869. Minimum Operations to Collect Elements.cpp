class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        int count = 0;
        int decr = k;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= k && map.find(nums[i]) == map.end()) {
                map[nums[i]]++;
                decr--;
            }
            count++;
            if (decr == 0) break;
        }

        return count;
    }
};