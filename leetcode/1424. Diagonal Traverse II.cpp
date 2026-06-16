class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();

        // {sum, elements}
        vector<vector<int>> map;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (i + j >= map.size()) map.resize(i + j + 1);
                map[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> result;
        for (int i = 0; i < map.size(); i++) {
            for (int j = map[i].size() - 1; j >= 0; j--) {
                result.push_back(map[i][j]);
            }
        }

        return result;
    }
};