class Solution {
    // {taskFinish, server}
    using p = array<int, 2>;
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        priority_queue<p, vector<p>, greater<>> pq;

        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int> requests(k, 0);
        int maxReq = 0;
        for (int i = 0; i < n; i++) {
            int t = arrival[i];
            // Check availability
            while (!pq.empty() && pq.top()[0] <= t) {
                available.insert(pq.top()[1]);
                pq.pop();
            }
            if (available.empty()) continue;

            // Acquire server
            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();
            int server = *it;

            pq.push({t + load[i], server});
            available.erase(server);
            requests[server]++;
            maxReq = max(maxReq, requests[server]);
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxReq) {
                result.push_back(i);
            }
        }
        return result;
    }
};