class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;

        for (int i = 0; i < tasks.size(); i++) {
            map[tasks[i]]++;
        }

        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (auto entry : map) {
            pq.push(entry.second);
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            while (!q.empty()) {
                auto [freq, enqueueTime] = q.front();
                if (enqueueTime <= time) {
                    q.pop();
                    pq.push(freq);
                }
                else break;
            }
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                if (freq > 1) q.push({freq - 1, time + n + 1});
            }
            if (pq.empty() && !q.empty()) {
                time = q.front().second;
            }
            else time++;
        }

        return time;
    }
};