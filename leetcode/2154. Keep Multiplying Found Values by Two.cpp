class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
        }

        while (true) {
            if (map[original] == true) original *= 2;
            else return original;
        }
    }
};