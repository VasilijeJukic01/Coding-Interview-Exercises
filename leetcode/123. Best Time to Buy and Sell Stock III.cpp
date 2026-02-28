class Solution {
public:
    using v = vector<vector<int>>;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // [2] x [3]
        vector<vector<int>> currDay(2, vector<int>(3, 0));
        
        for (int day = n - 1; day >= 0; day--) {
            for (int state = 0; state <= 1; state++) {
                for (int k = 1; k <= 2; k++) {
                    int doNothing = currDay[state][k];
                    int doSomething = 0;

                    // Buy
                    if (state == 0) {
                        doSomething = -prices[day] + currDay[1][k];
                    }
                    // Sell
                    else doSomething = prices[day] + currDay[0][k - 1];

                    currDay[state][k] = max(doNothing, doSomething);
                }
            }
        }

        return currDay[0][2];
    }
};