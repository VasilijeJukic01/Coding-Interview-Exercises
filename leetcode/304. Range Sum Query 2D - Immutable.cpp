class NumMatrix {
    vector<vector<int>> pSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        pSum.resize(m, vector<int>(n, 0));
        pSum[0][0] = matrix[0][0];

        for (int j = 1; j < n; j++) {
            pSum[0][j] = pSum[0][j - 1] + matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            pSum[i][0] = pSum[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                pSum[i][j] = matrix[i][j] + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int upper = (row1 - 1 >= 0) ? pSum[row1 - 1][col2] : 0;
        int left = (col1 - 1 >= 0) ? pSum[row2][col1 - 1] : 0;
        int corner = (row1 - 1 >= 0 && col1 - 1 >= 0) ? pSum[row1 - 1][col1 - 1] : 0;

        return pSum[row2][col2] - upper - left + corner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */