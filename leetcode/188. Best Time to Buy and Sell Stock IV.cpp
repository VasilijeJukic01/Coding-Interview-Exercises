class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // [2] x [k]
        vector<vector<int>> currDay(2, vector<int>(k + 1, 0));
        for (int day = n - 1; day >= 0; day--) {
            for (int state = 0; state <= 1; state++) {
                for (int c = 1; c <= k; c++) {
                    int doNothing = currDay[state][c];
                    int doSomething = 0;

                    // Buy
                    if (state == 0) {
                        doSomething = -prices[day] + currDay[1][c];
                    }
                    // Sell
                    else doSomething = prices[day] + currDay[0][c - 1];

                    currDay[state][c] = max(doNothing, doSomething);
                }
            }
        }

        return currDay[0][k];
    }
};