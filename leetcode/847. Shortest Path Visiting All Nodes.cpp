class Solution {
public:
    // {node, state}
    using p = array<int, 2>;

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> memo(n, vector<int>(1 << n, 0));

        queue<p> q;
        for (int i = 0; i < graph.size(); i++) {
            q.push({i, 1 << i});
            memo[i][1 << i] = 1;
        }

        int pathLen = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [v, state] = q.front();
                if (state == (1 << n) - 1) return pathLen;
                q.pop();

                for (auto& u : graph[v]) {
                    int mask = state | (1 << u);
                    if (memo[u][mask]) continue;
                    memo[u][mask] = mask;
                    q.push({u, mask});
                }
            }
            pathLen++;
        }
        
        return pathLen;
    }
};