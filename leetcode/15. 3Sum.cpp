class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());

         for (int k = 0; k < nums.size(); k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int left = k + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[k] + nums[left] + nums[right];
                if (sum == 0) {
                    if (v.empty() || v.back()[0] != nums[k] || v.back()[2] != nums[right]) {
                        v.push_back({nums[k], nums[left], nums[right]});
                    }
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
         }

        return v;
    }
};