class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> p(n, vector<int>(m));
        long long prod = 1;
        // Left
        for (int i = 0; i < n * m; i++) {
            int row = i / m;
            int col = i % m;
            p[row][col] = prod;
            prod = (prod * grid[row][col]) % 12345;
        }
        // Right
        prod = 1;
        for (int i = n * m - 1; i >= 0; i--) {
            int row = i / m;
            int col = i % m;
            p[row][col] = (p[row][col] * prod) % 12345;
            prod = (prod * grid[row][col]) % 12345;
        }

        return p;
    }
};