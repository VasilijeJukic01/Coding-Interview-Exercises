class Solution {
public:
    long long dfs(vector<vector<int>> &adjList, int node, vector<int>& baseTime) {
        if (adjList[node].empty()) return baseTime[node];

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        for (auto& child : adjList[node]) {
            long long time = dfs(adjList, child, baseTime);
            earliest = min(earliest, time);
            latest = max(latest, time);
        }

        return latest + ((latest - earliest) + baseTime[node]);
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adjList(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adjList[u].push_back(v);
        }

        return dfs(adjList, 0, baseTime);
    }
};