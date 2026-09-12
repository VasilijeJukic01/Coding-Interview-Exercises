class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }

        int total = 0;
        for (auto& [_, indices]: map) {
            if (indices.size() != 3) continue;
            int d1 = indices[1] - indices[0];
            int d2 = indices[2] - indices[1];
            if (d1 == d2) total++;
        }

        return total;
    }
};