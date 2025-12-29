class Solution {
public:
    using p = array<int, 2>;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<p, vector<p>, greater<>> available;

        vector<int> result;
        int index = 0;
        long long time = tasks[index][0];
        while (index < n || !available.empty()) {
            // Check availability
            if (available.empty() && index < n) {
                time = max(time, (long long) tasks[index][0]);
            }
            while (index < n && tasks[index][0] <= time) {
                available.push({tasks[index][1], tasks[index][2]});
                index++;
            }
            // Process task
            auto [endTime, taskIndex] = available.top();
            available.pop();
            result.push_back(taskIndex);

            time += endTime;
        }

        return result;
    }
};