class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> tracker;
        int total = 0;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            tracker[nums[right]]++;

            while (tracker.size() > k) {
                tracker[nums[left]]--;
                if (tracker[nums[left]] == 0) {
                    tracker.erase(nums[left]);
                }
                left++;
            }

            if (tracker.size() <= k) {
                total += (right - left + 1);
            }
        }

        return total;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> checker;
        for (int i = 0; i < n; i++) {
            checker.insert(nums[i]);
        }
        int k = checker.size();

        return solve(nums, k) - solve(nums, k - 1);
    }
};