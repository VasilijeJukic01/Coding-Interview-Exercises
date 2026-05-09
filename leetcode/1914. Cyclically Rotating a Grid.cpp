class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int rings = min(m, n) / 2;
        for (int r = 0; r < rings; r++) {
            vector<int> layer;
            for (int j = r; j < n - r; j++) {
                layer.push_back(grid[r][j]);
            }
            for (int i = r + 1; i < m - r; i++) {
                layer.push_back(grid[i][n - r - 1]);
            }
            for (int j = n - r - 2; j >= r; j--) {
                layer.push_back(grid[m - r - 1][j]);
            }
            for (int i = m - r - 2; i > r; i--) {
                layer.push_back(grid[i][r]);
            }

            int shifts = k % layer.size();
            rotate(layer.begin(), layer.begin() + shifts, layer.end());

            int write = 0;
            for (int j = r; j < n - r; j++) {
                grid[r][j] = layer[write++];
            }
            for (int i = r + 1; i < m - r; i++) {
                grid[i][n - r - 1] = layer[write++];
            }
            for (int j = n - r - 2; j >= r; j--) {
                grid[m - r - 1][j] = layer[write++];
            }
            for (int i = m - r - 2; i > r; i--) {
                grid[i][r] = layer[write++];
            }
        }

        return grid;
    }
};