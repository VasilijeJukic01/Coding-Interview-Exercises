class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
        }

        vector<int> vals;
        for (auto [k, v] : map) {
            vals.push_back(k);
        }

        sort(vals.begin(), vals.end());

        vector<int> dp(vals.size() + 1, 0);
        for (int i = vals.size() - 1; i >= 0; i--) {
            int skip = dp[i + 1];
            int remove = map[vals[i]] * vals[i];
            if (i < vals.size() - 1 && vals[i + 1] == vals[i] + 1) {
                remove += dp[i + 2];
            }
            else remove += dp[i + 1];
            
            dp[i] = max(skip, remove);
        }

        return dp[0];
    }
};