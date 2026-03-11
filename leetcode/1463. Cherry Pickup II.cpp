class Solution {
public:
    using table = vector<vector<int>>;

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        table curr(cols, vector<int>(cols, -1e9));
        table next(cols, vector<int>(cols, -1e9));

        for (int c1 = 0; c1 < cols; c1++) {
            for (int c2 = 0; c2 < cols; c2++) {
                curr[c1][c2] = 0;
                next[c1][c2] = 0;
            }
        }

        for (int r = rows - 1; r >= 0; r--) {
            for (int c1 = 0; c1 < cols; c1++) {
                for (int c2 = 0; c2 < cols; c2++) {
                    int cherries = 0;
                    if (c1 == c2) cherries = grid[r][c1];
                    else cherries = grid[r][c1] + grid[r][c2];

                    int best = -1e9;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            if (c1 + d1 < 0 || c2 + d2 < 0) continue;
                            if (c1 + d1 >= cols || c2 + d2 >= cols) continue;
                            best = max(best, curr[c1 + d1][c2 + d2]);
                        }
                    }

                    next[c1][c2] = cherries + best;
                }
            }
            curr = next;
        }

        return curr[0][cols - 1];
    }
};