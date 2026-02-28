class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // q0 - ready state
        // q1 - holding state
        int q0 = 0;
        int q1 = -prices[0];

        // q0 -> q0 (wait), q0 -> q1 (buy)
        // q1 -> q1 (wait), q1 -> q0 (sell)
        for (int i = 1; i < n; i++) {
            int prevQ0 = q0, prevQ1 = q1;
            
            q1 = max(prevQ1, prevQ0 - prices[i]);
            q0 = max(prevQ0, prevQ1 + prices[i] - fee);
        }

        return q0;
    }
};