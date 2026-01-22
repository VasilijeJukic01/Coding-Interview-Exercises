class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> colorMap(graph.size(), 'X');

        for (int k = 0; k < graph.size(); k++) {
            if (colorMap[k] != 'X') continue;

            queue<int> q;
            q.push(k);
            colorMap[k] = 'R';

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int i = 0; i < graph[curr].size(); i++) {
                    int neighbor = graph[curr][i];
                    // Doesnt have color
                    if (colorMap[neighbor] == 'X') {
                        if (colorMap[curr] == 'R') {
                            colorMap[neighbor] = 'B';
                        }
                        else colorMap[neighbor] = 'R';

                        q.push(neighbor);
                    }
                    // Check color matching
                    else {
                        if (colorMap[curr] == 'R' && colorMap[neighbor] == 'R') {
                            return false;
                        }
                        if (colorMap[curr] == 'B' && colorMap[neighbor] == 'B') {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};