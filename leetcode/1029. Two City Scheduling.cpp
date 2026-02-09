class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), 
            [](const vector<int>& c1, const vector<int>& c2) {
                return abs(c1[0] - c1[1]) > abs(c2[0] - c2[1]);
        });

        int n = costs.size() / 2;
        int counterA = n, counterB = n;

        int cost = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (counterA > 0 && counterB > 0) {
                if (costs[i][0] < costs[i][1]) counterA--;
                else counterB--;

                cost += min(costs[i][0], costs[i][1]);
            }
            else if (counterA > 0) cost += costs[i][0];
            else cost += costs[i][1];
        }

        return cost;
    }
};