class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, vector<int>& rods, int diff, int i) {
        if (i == rods.size() && diff == 0) return 0;
        if (i == rods.size()) return -10000;

        if (memo[i][diff] != -1) {
            return memo[i][diff];
        }

        int exclude = solve(memo, rods, diff, i+1);
        // Put on taller support
        int include1 = solve(memo, rods, diff + rods[i], i+1);
        // Put on shorter support
        int include2 = min(diff, rods[i]) + solve(memo, rods, abs(diff - rods[i]), i+1);

        return memo[i][diff] = max(max(include1, include2), exclude);
    }

    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        
        table memo(rods.size(), vector<int>(sum + 1, -1));
        return solve(memo, rods, 0, 0);
    }
};