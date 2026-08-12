class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) break;
            curr += nums[i];
        }

        unordered_set<int> cand(nums.begin(), nums.end());
        while (cand.count(curr)) {
            curr++;
        }

        return curr;
    }
};