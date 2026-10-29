class Solution {
public:
    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int i = 0, j = 0;
        int moves = m * n;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        while (true) {
            char dir = grid[i][j];

            int nextI = i, nextJ = j;
            if (dir == 'R') nextJ++;
            else if (dir == 'D') nextI++;
            else if (dir == 'L') nextJ--;
            else nextI--;

            if (!isSafe(nextI, nextJ, m, n)) break;
            if (visited[nextI][nextJ]) break;

            // Visited
            i = nextI, j = nextJ;
            visited[i][j] = true;
        }

        return {i, j};
    }
};