class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pSum[i + 1][j + 1] = mat[i][j] + pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j];
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int startI = max(0, i - k), startJ = max(0, j - k);
                int endI = min(m - 1, i + k), endJ = min(n - 1, j + k);

                int upper = pSum[startI][endJ + 1];
                int left = pSum[endI + 1][startJ];
                int intersect = pSum[startI][startJ];

                res[i][j] = pSum[endI + 1][endJ + 1] - upper - left + intersect;
            }
        }

        return res;
    }
};