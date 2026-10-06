class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Upper Triangle
        for (int k = 0; k < n - 1; k++) {
            int row = 0;
            int col = n - k - 1;

            vector<int> diagonal;
            while (col < n) {
                diagonal.push_back(grid[row][col]);
                col++;
                row++;
            }

            sort(diagonal.rbegin(), diagonal.rend());
            row = 0;
            col = n - k - 1;
            while (col < n) {
                grid[row][col] = diagonal.back();
                diagonal.pop_back();
                col++;
                row++;
            }
        }

        // Lowe Triangle
        for (int k = 0; k < n; k++) {
            int row = k;
            int col = 0;

            vector<int> diagonal;
            while (row < n) {
                diagonal.push_back(grid[row][col]);
                col++;
                row++;
            }

            sort(diagonal.begin(), diagonal.end());
            row = k;
            col = 0;
            while (row < n) {
                grid[row][col] = diagonal.back();
                diagonal.pop_back();
                col++;
                row++;
            }
        }

        return grid;
    }
};