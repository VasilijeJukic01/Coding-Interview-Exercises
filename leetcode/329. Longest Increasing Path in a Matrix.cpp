class Solution {
public:
    using grid = vector<vector<int>>;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int solve(grid& memo, grid& mat, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];

        int path = 1;
        for (int k = 0; k < 4; k++) {
            int nI = i + y[k];
            int nJ = j + x[k];

            if (!isSafe(nI, nJ, mat.size(), mat[0].size())) continue;
            if (mat[nI][nJ] == -1) continue;

            if (mat[nI][nJ] > mat[i][j]) {
                path = max(path, 1 + solve(memo, mat, nI, nJ));
            }
        }

        return memo[i][j] = path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        grid memo(m, vector<int>(n, -1));

        int longest = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longest = max(longest, solve(memo, matrix, i, j));
            }
        }

        return longest;
    }
};