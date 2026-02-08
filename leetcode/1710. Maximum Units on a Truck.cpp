class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
            [](const vector<int>& x, const vector<int>& y) {
                return x[1] > y[1];
        });

        int units = 0;
        int weight = 0;
        for (auto& box : boxTypes) {
            int take = min(box[0], truckSize - weight);
            weight += take;
            units += take * box[1];
            if (weight == truckSize) break;
        }

        return units;
    }
};