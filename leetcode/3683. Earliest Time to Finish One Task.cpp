class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minimum = 999;

        for (int i = 0; i < tasks.size(); i++) {
            minimum = min(minimum, tasks[i][0] + tasks[i][1]);
        }

        return minimum;
    }
};