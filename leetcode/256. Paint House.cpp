class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();

        int currRed = costs[0][0];
        int currBlue = costs[0][1];
        int currGreen = costs[0][2];

        for (int i = 1; i < n; i++) {
            int prevRed = currRed;
            int prevBlue = currBlue;
            int prevGreen = currGreen;

            currRed = costs[i][0] + min(prevBlue, prevGreen);
            currBlue = costs[i][1] + min(prevRed, prevGreen);
            currGreen = costs[i][2] + min(prevBlue, prevRed);
        }

        return min(currRed, min(currBlue, currGreen));
    }
};