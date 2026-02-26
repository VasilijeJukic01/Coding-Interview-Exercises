class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();

        vector<vector<int>> state(n, vector<int>(k, 0));

        int minCost = INT_MAX;
        int minCostIndex = 0;
        for (int j = 0; j < k; j++) {
            state[0][j] = costs[0][j];
            if (state[0][j] < minCost) {
                minCost = state[0][j];
                minCostIndex = j;
            }
        }

        int secondMinCost = INT_MAX;
        for (int j = 0; j < k; j++) {
            if (j == minCostIndex) continue;
            secondMinCost = min(secondMinCost, state[0][j]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (j == minCostIndex) {
                    state[i][j] = costs[i][j] + secondMinCost;
                }
                else state[i][j] = costs[i][j] + minCost;
            }

            minCost = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (state[i][j] < minCost) {
                    minCost = state[i][j];
                    minCostIndex = j;
                }
            }
            secondMinCost = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (j == minCostIndex) continue;
                secondMinCost = min(secondMinCost, state[i][j]);
            }
        }

        int best = INT_MAX;
        for (int i = 0; i < k; i++) {
            best = min(best, state[n-1][i]);
        }

        return best;
    }
};