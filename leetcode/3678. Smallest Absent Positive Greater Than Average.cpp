class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_map<int, bool> map;
        int x = 0;
        int counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = true;
            x += nums[i];
            counter++;
        }

        x /= counter;
        x = max(0, x);

        for (int i = x + 1; i <= 100; i++) {
            if (map[i] == false) return i;
        }

        return 101;
    }
};