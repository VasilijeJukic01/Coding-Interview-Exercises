class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        // {stop, buses}
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                adjList[routes[i][j]].push_back(i);
            }
        }

        vector<bool> visited(routes.size(), false);
        queue<int> q;
        q.push(source);

        int lines = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int currStop = q.front();
                q.pop();

                auto& busses = adjList[currStop];
                for (int i = 0; i < busses.size(); i++) {
                    if (visited[busses[i]] == true) continue;
                    auto& stops = routes[busses[i]];

                    for (int j = 0; j < stops.size(); j++) {
                        if (stops[j] == target) return lines;
                        q.push(stops[j]);
                    }
                    visited[busses[i]] = true;
                }

            }
            lines++;
        }

        return -1;
    }
};