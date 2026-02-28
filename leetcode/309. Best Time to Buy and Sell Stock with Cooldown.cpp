class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // q0 - free state
        // q1 - holding state
        // q2 - sold state
        int q0 = 0;
        int q1 = -prices[0];
        int q2 = 0;

        // q0 -> q0 (waiting), q0 -> q1 (buy)
        // q1 -> q1 (waiting), q1 -> q2 (sell)
        // q2 -> q0 (cooldown)
        for (int i = 1; i < n; i++) {
            int prevQ1 = q1, prevQ2 = q2, prevQ0 = q0;

            q1 = max(prevQ1, prevQ0 - prices[i]);
            q2 = prevQ1 + prices[i];
            q0 = max(prevQ0, prevQ2);
        }

        return max(q0, q2);
    }
};