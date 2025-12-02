class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for_each(nums1.begin(), nums1.end(), [&map1](int num) {
            map1[num]++;
        });

        for_each(nums2.begin(), nums2.end(), [&map2](int num) {
            map2[num]++;
        });

        vector<int> diff1, diff2;

        for_each(map1.begin(), map1.end(), [&map2, &diff1](const pair<int, int>& e) {
            if (map2.find(e.first) == map2.end()) diff1.push_back(e.first);
        });

        for_each(map2.begin(), map2.end(), [&map1, &diff2](const pair<int, int>& e) {
            if (map1.find(e.first) == map1.end()) diff2.push_back(e.first);
        });

        return {diff1, diff2};
    }
};