class Solution {
    using vv = vector<vector<int>>;
public:
    void solve(vv& result, vv& graph, vector<int>& curr, int node) {
        if (node == graph.size() - 1) {
            curr.push_back(node);
            result.push_back(curr);
            curr.pop_back();
            return;
        }

        for (auto& next : graph[node]) {
            curr.push_back(node);
            solve(result, graph, curr, next);
            // Backtrack
            curr.pop_back();
        }
    }

    vv allPathsSourceTarget(vv& graph) {
        vv result;
        vector<int> curr;
        solve(result, graph, curr, 0);

        return result;
    }
};