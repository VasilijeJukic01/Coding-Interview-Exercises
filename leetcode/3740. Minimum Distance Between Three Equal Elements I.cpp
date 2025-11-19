class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }

        int minDiff = INT_MAX;
        for (auto item : map) {
            if (item.second.size() < 3) continue;
            for (int i = 0; i < item.second.size() - 2; i++) {
                vector<int> a = item.second;
                int sum = abs(a[i] - a[i+1]) + abs(a[i+1] - a[i+2]) + abs(a[i+2] - a[i]);
                minDiff = min(minDiff, sum);
            }
        }

        if (minDiff == INT_MAX) return -1;
        return minDiff;
    }
};