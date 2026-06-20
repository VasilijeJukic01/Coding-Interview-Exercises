class Solution {
public:
    int solve(vector<int> &memo, int i, vector<bool> &covered, int n) {
        if (i >= n) return 0;

        if (memo[i] != -1) return memo[i];

        if (covered[i]) {
            memo[i] = solve(memo, i + 1, covered, n);
        }
        else {
            int placeHere = 1 + solve(memo, i + 2, covered, n);
            int placeNext = 1 + solve(memo, i + 3, covered, n);

            memo[i] = min(placeHere, placeNext);
        }

        return memo[i];
    }
    
    int minLights(vector<int>& lights) {
        int n = lights.size();

        // [0, 1, 0, 0, -1, 0]
        // range of light
        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int lower = max(0, i - lights[i]);
                int upper = min(n - 1, i + lights[i]);
                pSum[lower]++;
                pSum[upper + 1]--;
            }
        }

        vector<bool> covered(n, false);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pSum[i];
            if (sum > 0) covered[i] = true;
        }

        vector<int> memo(n, -1);
        return solve(memo, 0, covered, n);
    }
};