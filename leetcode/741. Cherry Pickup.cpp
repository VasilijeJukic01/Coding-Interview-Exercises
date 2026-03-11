class Solution {
public:
    using table = vector<vector<int>>;
    using cache = vector<vector<vector<int>>>;

    int solve(cache& memo, table& grid, int r1, int c1, int r2, int n) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n) return -1e9;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;

        if (r1 == n - 1 && c1 == n - 1) return grid[n-1][n-1];

        if (memo[r1][c1][r2] != -1) {
            return memo[r1][c1][r2];
        }

        int cherries = 0;
        if (r1 == r2 && c1 == c2) cherries = grid[r1][c1];
        else cherries = grid[r1][c1] + grid[r2][c2];

        int rr = solve(memo, grid, r1, c1 + 1, r2, n);
        int rd = solve(memo, grid, r1, c1 + 1, r2 + 1, n);
        int dr = solve(memo, grid, r1 + 1, c1, r2, n);
        int dd = solve(memo, grid, r1 + 1, c1, r2 + 1, n);

        return memo[r1][c1][r2] = cherries + max({rr, rd, dr, dd});
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        cache memo(n, table(n, vector<int>(n, -1)));
        return max(0, solve(memo, grid, 0, 0, 0, n));
    }
};