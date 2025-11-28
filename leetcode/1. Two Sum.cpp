class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        int x, y;
        for (auto item : map) {
            if (map.find(target - item.first) != map.end()) {
                x = item.first;
                y = map[target - item.first];
                break;
            }
        }

        return {};
    }
};