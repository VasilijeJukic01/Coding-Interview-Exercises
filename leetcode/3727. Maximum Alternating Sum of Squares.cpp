class Solution {
    using ll = long long;
public:
    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) continue;
            nums[i] = -nums[i];
        }

        sort(nums.begin(), nums.end());

        ll sum = 0;
        int left = 0, right = n - 1;
        while (left <= right) {
            ll first = nums[left] * nums[left];
            ll second = nums[right] * nums[right];

            if (left == right) sum += first;
            else sum += second - first;

            left++;
            right--;
        }

        return sum;
    }
};