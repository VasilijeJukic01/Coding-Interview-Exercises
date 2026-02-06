class Solution {
public:
    unordered_map<string, vector<string>> adjList;

    void hierholzer(vector<string>& result, string v) {
        auto& edges = adjList[v];
        while (!edges.empty()) {
            string curr = edges.back();
            edges.pop_back();
            hierholzer(result, curr);
        }
        result.push_back(v);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& e : tickets) {
            adjList[e[0]].push_back(e[1]);
        }

        for (auto& [v, neighbors] : adjList) {
            sort(neighbors.rbegin(), neighbors.rend());
        }
        
        vector<string> result;
        hierholzer(result, "JFK");
        reverse(result.begin(), result.end());

        return result;
    }
};