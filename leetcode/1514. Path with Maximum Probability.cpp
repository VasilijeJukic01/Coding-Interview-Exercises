class Solution {
public:
    // {weight, dest}
    using p = array<double, 2>;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<p>> adjList(n);

        for (int i = 0; i < edges.size(); i++) {
            double u = edges[i][0];
            double v = edges[i][1];
            double w = succProb[i];
            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }

        vector<double> prob(n);
        priority_queue<p> pq;
        pq.push({1, (double) start_node});
        prob[start_node] = 1;

        while (!pq.empty()) {
            auto [currCost, u] = pq.top();
            pq.pop();

            if (currCost < prob[u]) continue;

            for (auto& neighbor : adjList[u]) {
                double v = neighbor[1];
                double w = neighbor[0];

                if (currCost * w > prob[v]) {
                    prob[v] = currCost * w;
                    pq.push({prob[v], v});
                }
            }
        }

        return prob[end_node];
    }
};