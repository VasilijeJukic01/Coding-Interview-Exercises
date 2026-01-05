class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // {line, gaps}
        unordered_map<long long, int> map;

        int n = wall.size();
        long long m = accumulate(wall[0].begin(), wall[0].end(), 0LL);

        for (int i = 0; i < n; i++) {
            long long col = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                col += wall[i][j];
                if (col < m) map[col]++;
            }
        }

        long long bestCut = 0;
        for (auto& [_, cuts] : map) {
            if (cuts > bestCut) bestCut = cuts;
        }

        return n - bestCut;
    }
};