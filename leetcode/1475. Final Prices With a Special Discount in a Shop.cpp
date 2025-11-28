class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        vector<int> result(prices.begin(), prices.end());

        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }

            if (!s.empty()) result[i] = prices[i] - s.top();

            s.push(prices[i]);
        }

        return result;
    }
};