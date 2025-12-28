class Solution {
public:
    // {timeLeft, chairNum}
    using p = pair<int, int>;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<p, vector<p>, greater<>> occupied;

        for (int i = 0; i < n; i++) {
            times[i].push_back(i);
            available.push(i);
        }

        sort(times.begin(), times.end());

        int index = 0;
        while (index < n) {
            int time = times[index][0];
            // Check occupied
            while (!occupied.empty()) {
                auto [timeLeft, chairNum] = occupied.top();
                if (timeLeft > time) break;
                available.push(chairNum);
                occupied.pop();
            }
            // Check arival
            if (times[index][0] <= time) {
                int chair = available.top();
                if (times[index][2] == targetFriend) return chair;
                available.pop();
                occupied.push({times[index][1], chair});
                index++;
            }
        }

        return 0;
    }
};