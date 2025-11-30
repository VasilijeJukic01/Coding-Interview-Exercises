class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (n & 1 && i == n / 2) sum += mat[i][i];
            else sum += mat[i][i] + mat[i][n-1-i];
        }

        return sum;
    }
};