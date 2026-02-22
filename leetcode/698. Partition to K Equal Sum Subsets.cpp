class Solution {
public:
    // -1 = didnt explore that combination
    //  1 = success combination
    //  0 = dead end (tried all possible paths from there but failed)
    vector<int> memo;

    bool dfs(vector<int>& nums, int target, int mask, int sum) {
        if (mask == (1 << nums.size()) - 1) return true;

        // Explored this combination already
        if (memo[mask] != -1) return memo[mask];

        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                // Cant fit
                if (nums[i] + sum > target) continue;

                int newMask = mask | (1 << i);
                int newSum = (sum + nums[i]) % target;
                if (dfs(nums, target, newMask, newSum)) {
                    return memo[mask] = 1;
                }
            }
        }

        return memo[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % k != 0) return false;

        int target = sum / k;
        memo.resize(1 << n, -1);
        sort(nums.rbegin(), nums.rend());

        return dfs(nums, target, 0, 0);
    }
};