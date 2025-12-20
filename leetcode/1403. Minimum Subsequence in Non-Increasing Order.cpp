class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> map(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        int currSum = 0;
        vector<int> result;
        for (int i = 100; i >= 0; i--) {
            while (map[i] > 0 && currSum <= sum - currSum) {
                currSum += i;
                map[i]--;
                result.push_back(i);
            }
            if (currSum > sum - currSum) break;
        }

        return result;
    }
};