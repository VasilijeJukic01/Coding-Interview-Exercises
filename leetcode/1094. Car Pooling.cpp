class Solution {
public:

    // {endTime, passengers}
    using p = pair<int, int>;

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(), [](const vector<int>& t1, const vector<int>& t2) {
            return t1[1] < t2[1];
        });

        priority_queue<p, vector<p>, greater<>> occupied;

        int index = 0;
        int currPassengers = 0;
        while (index < n) {
            int time = trips[index][1];
            // Check
            while (!occupied.empty()) {
                auto [endTime, passengers] = occupied.top();
                if (endTime <= time) {
                    occupied.pop();
                    currPassengers -= passengers;
                }
                else break;

            }
            // Occupy
            vector<int> trip = trips[index++];
            currPassengers += trip[0];
            if (currPassengers > capacity) return false;
            occupied.push({trip[2], trip[0]});
        }

        return true;
    }
};