class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        int count = 1;
        queue<int> q;
        vector<int> visited(n, false);
        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int room = q.front();
            q.pop();

            for (auto& next : rooms[room]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    count++;
                }
            }
        }

        return count == n;
    }
};