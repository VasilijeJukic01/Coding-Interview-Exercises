class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // {val, count}
        unordered_map<int, int> map;

        int longest = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            map[nums[right]]++;
            while (map[nums[right]] > k) {
                map[nums[left]]--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};