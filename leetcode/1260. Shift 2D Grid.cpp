class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int len = m * n;
        k = k % len;

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newIdx = (i * n + j + k) % len;
                
                int nI = newIdx / n;
                int nC = newIdx % n;
                result[nI][nC] = grid[i][j];
            }
        }

        return result;
    }
};