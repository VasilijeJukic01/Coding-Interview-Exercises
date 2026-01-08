class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int best = 0;
        // {sum, index}
        unordered_map<int, int> map;
        map[0] = -1;

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i] == 1 ? 1 : -1;
            if (map.count(currSum)) {
                best = max(best, i - map[currSum]);
            }
            else map[currSum] = i;
        }

        return best;
    }
};