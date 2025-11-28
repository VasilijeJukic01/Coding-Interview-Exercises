class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&map](int a, int b) {
            if (map[a] != map[b]) return map[a] < map[b];
            return a > b;
        });

        return nums;
    }
};