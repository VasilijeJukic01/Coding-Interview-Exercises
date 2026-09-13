class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }

        int total = 0;
        for (auto& [_, indices] : map) {
            if (indices.size() < 3) continue;

            bool valid = true;
            int gap = indices[1] - indices[0];
            for (int i = 2; i < indices.size(); i++) {
                int curr = indices[i] - indices[i - 1];
                if (curr != gap) valid = false;
                if (!valid) break;
            }

            if (valid) total++;
        }

        return total;
    }
};