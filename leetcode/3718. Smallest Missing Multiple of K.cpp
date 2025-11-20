class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
        }

        for (int i = 1; i <= 101; i++) {
            int n = k * i;
            if (map[n] == false) return n;
        }

        return 0;
    }
};