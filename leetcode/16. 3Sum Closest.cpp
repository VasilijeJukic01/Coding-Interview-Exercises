class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int distance = INT_MAX;
        int bestSum = 0;
        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            int left = k + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[k] + nums[left] + nums[right];
                if (sum == target) return sum;
                
                if (abs(target - sum) < distance) {
                    distance = abs(target - sum);
                    bestSum = sum;
                }
                if (sum < target) left++;
                else right--;
            }
        }

        return bestSum;
    }
};