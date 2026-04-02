class Solution {
public:
    using event = array<int, 2>;

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<event> events(2 * n);

        int write = 0;
        for (int i = 0; i < n; i++) {
            events[write] = {buildings[i][0], -buildings[i][2]};
            events[write + 1] = {buildings[i][1], buildings[i][2]};
            write += 2;
        }

        sort(events.begin(), events.end());

        multiset<int, greater<int>> ms = {0};
        vector<vector<int>> result;
        for (auto& e : events) {
            int x = e[0];
            int h = e[1];
            
            int prevMax = *ms.begin();
            if (h < 0) ms.insert(-h);
            else ms.erase(ms.find(h));

            int currMax = *ms.begin();
            if (currMax != prevMax) {
                result.push_back({x, currMax});
            }
        }

        return result;
    }
};