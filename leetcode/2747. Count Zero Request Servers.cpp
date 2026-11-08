class Solution {
    // {time, id}
    using p = array<int, 2>;
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        sort(logs.begin(), logs.end(), []
            (const vector<int>& x, const vector<int>& y){
                return x[1] < y[1];
        });

        vector<int> res(queries.size());

        vector<p> sorted(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            sorted[i] = {queries[i], i};
        }
        sort(sorted.begin(), sorted.end());

        int curr = 0;
        int active = 0;
        vector<int> seen(n + 1, 0);
        priority_queue<p, vector<p>, greater<>> pq;
        for (int q = 0; q < queries.size(); q++) {
            int start = sorted[q][0] - x, end = sorted[q][0];

            while (curr < m && logs[curr][1] <= end) {
                int server = logs[curr][0];
                int t = logs[curr][1];
                pq.push({t, server});
                if (seen[server] == 0) active++;
                seen[server]++;
                curr++;
            }

            while (!pq.empty() && pq.top()[0] < start) {
                int server = pq.top()[1];
                seen[server]--;
                if (seen[server] == 0) active--;
                pq.pop();
            }

            res[sorted[q][1]] = n - active;
        }

        return res;
    }
};