class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long total = 0;
        long long window = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) window++;
            else {
                total += window * (window + 1) / 2;
                window = 1;
            }
        }

        total += window * (window + 1) / 2;

        return total;
    }
};