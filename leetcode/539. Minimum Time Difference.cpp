class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> data;

        for (auto& time : timePoints) {
            string hours = time.substr(0, 2);
            string minutes = time.substr(3, 2);

            int val = stoi(hours) * 60 + stoi(minutes);
            data.push_back(val);
        }

        sort(data.begin(), data.end());

        int best = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            best = min(best, data[i + 1] - data[i]);
        }

        int circularDiff = 1440 - data[n - 1] + data[0];
        best = min(best, circularDiff);

        return best;
    }
};