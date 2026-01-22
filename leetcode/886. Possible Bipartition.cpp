class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n + 1);

        for (auto& dislike : dislikes) {
            int u = dislike[0];
            int v = dislike[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<char> colorMap(n + 1, 'N');
        for (int i = 1; i <= n; i++) {
            if (colorMap[i] != 'N') continue;

            queue<int> q;
            q.push(i);
            colorMap[i] = 'R';
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int k = 0; k < adjList[curr].size(); k++) {
                    int neighbor = adjList[curr][k];
                    // Not visited
                    if (colorMap[neighbor] == 'N') {
                        if (colorMap[curr] == 'R') colorMap[neighbor] = 'B';
                        else colorMap[neighbor] = 'R';
                        q.push(neighbor);
                    }
                    // Check colors
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