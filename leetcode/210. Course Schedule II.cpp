class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indeg(numCourses);

        for (auto& p : prerequisites) {
            int u = p[0];
            int v = p[1];
            adjList[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;
        int visited = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                visited++;
            }
        }

        vector<int> schedule;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& n : adjList[curr]) {
                indeg[n]--;
                if (indeg[n] == 0) {
                    q.push(n);
                    visited++;
                }
            }
            schedule.push_back(curr);
        }

        if (visited < numCourses) return {};
        return schedule;
    }
};