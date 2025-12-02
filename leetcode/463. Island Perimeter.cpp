class Solution {
public:
    int isWater(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n) return 1;
        return grid[i][j] == 0;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) continue;

                int left = isWater(grid, i, j-1);
                int right = isWater(grid, i, j+1);
                int up = isWater(grid, i-1, j);
                int down = isWater(grid, i+1, j);

                perimeter += left + right + up + down;
            }
        }

        return perimeter;
    }
};