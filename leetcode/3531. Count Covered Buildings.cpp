class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> x(n + 1, {n + 1, 0});
        vector<pair<int, int>> y(n + 1, {n + 1, 0});

        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];

            x[b] = {min(x[b].first, a), max(x[b].second, a)};
            y[a] = {min(y[a].first, b), max(y[a].second, b)};
        }

        int total = 0;
        for (int i = 0; i < buildings.size(); i++) {
            int a = buildings[i][0];
            int b = buildings[i][1];

            if (a > x[b].first && a < x[b].second && b > y[a].first && b < y[a].second) {
                total++;
            }
        }

        return total;
    }
};