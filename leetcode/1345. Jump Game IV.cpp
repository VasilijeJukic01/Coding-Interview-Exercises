class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < n; i++) {
            lookup[arr[i]].push_back(i);
        }

        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int steps = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int k = 0; k < len; k++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) return steps;
                if (lookup.count(arr[curr])) {
                    for (auto& adj : lookup[arr[curr]]) {
                        if (!visited[adj]) {
                            visited[adj] = true;
                            q.push(adj);
                        }
                    }
                    lookup.erase(arr[curr]);
                }

                if (curr > 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                if (curr < n - 1 && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
            }
            steps++;
        }

        return n;
    }
};