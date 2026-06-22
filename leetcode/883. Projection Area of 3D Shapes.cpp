class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int total = 0;

        for (int i = 0; i < grid.size(); i++) {
            int rowMax = 0;
            int colMax = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 0) total++;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            total += rowMax + colMax;
        }

        return total;
    }
};