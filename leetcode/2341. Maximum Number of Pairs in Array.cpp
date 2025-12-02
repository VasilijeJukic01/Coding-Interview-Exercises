class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> map;

        for_each(nums.begin(), nums.end(), [&map](int num) {
            map[num]++;
        });

        int x = 0, y = 0;

        for_each(map.begin(), map.end(), [&x, &y](const pair<int, int> e) {
            if (e.second & 1) y++;
            x += e.second / 2;
        });

        return {x, y};
    }
};