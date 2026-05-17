class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adjList(n);

        for (int i = 0; i < arr.size(); i++) {
            int forward = i + arr[i];
            if (forward < n) {
                adjList[i].push_back(forward);
            }
            int backward = i - arr[i];
            if (backward >= 0) {
                adjList[i].push_back(backward);
            }
        }

        queue<int> q;
        vector<bool> visited(n);
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            if (arr[curr] == 0) return true;
            q.pop();

            for (auto& adj : adjList[curr]) {
                if (visited[adj]) continue;
                q.push(adj);
                visited[adj] = true;
            }
        }

        return false;
    }
};