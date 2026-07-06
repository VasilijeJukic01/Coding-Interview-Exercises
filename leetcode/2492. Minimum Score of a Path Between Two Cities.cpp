class Solution {
    using p = array<int, 2>;

    void dfs(vector<vector<p>>& adjList, int u, vector<bool>& seen, int& score, int n) {
        seen[u] = true;

        for (auto& [v, w] : adjList[u]) {
            score = min(score, w);

            if (seen[v]) continue;
            dfs(adjList, v, seen, score, n);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<p>> adjList(n + 1);
        for (auto& e : roads) {
            int u = e[0], v = e[1];
            int w = e[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        int score = INT_MAX;
        vector<bool> seen(n + 1);
        dfs(adjList, 1, seen, score, n);

        return score;
    }
};