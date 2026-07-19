class Solution {
    using v = vector<int>;
    using vv = vector<vector<string>>;
public:
    int solve(v& memo, v& costs, vv& rules, int i, string& src, string& target) {
        if (i == src.size()) return 0;

        if (memo[i] != -1) return memo[i];

        int cost = 1e9;
        // Skip
        if (src[i] == target[i]) {
            cost = min(cost, solve(memo, costs, rules, i + 1, src, target));
        }
        // Apply
        for (int k = 0; k < rules.size(); k++) {
            string& p = rules[k][0];
            string& r = rules[k][1];

            if (i + p.size() <= src.size()) {
                bool canUse = true;
                for (int l = 0; l < p.size(); l++) {
                    // Check src match
                    if (p[l] != src[i + l] && p[l] != '*') {
                        canUse = false;
                        break;
                    }
                    // Check target match
                    if (r[l] != target[i + l]) {
                        canUse = false;
                        break;
                    }
                }
                if (canUse) {
                    int costP = costs[k] + solve(memo, costs, rules, i + p.size(), src, target);
                    cost = min(cost, costP);
                }
            }
        }

        return memo[i] = cost;
    }
    
    int minCost(string source, string target, vv& rules, v& costs) {
        for (int i = 0; i < rules.size(); i++) {
            for (int j = 0; j < rules[i][0].size(); j++) {
                if (rules[i][0][j] == '*') costs[i]++;
            }
        }

        vector<int> memo(source.size(), -1);
        
        int result = solve(memo, costs, rules, 0, source, target);
        if (result >= 1e9) return -1;
        return result;
    }
};