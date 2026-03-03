class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, vector<int>& stones, int sum, int pileA, int i) {
        if (i == stones.size()) {
            int pileB = sum - pileA;
            return abs(pileA - pileB);
        }

        if (memo[i][pileA] != -1) {
            return memo[i][pileA];
        }

        int dontInclude = solve(memo, stones, sum, pileA, i + 1);
        int include = solve(memo, stones, sum, pileA + stones[i], i + 1);

        return memo[i][pileA] = min(dontInclude, include);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        table memo(n, vector<int>(sum + 1, -1));

        return solve(memo, stones, sum, 0, 0);
    }
};