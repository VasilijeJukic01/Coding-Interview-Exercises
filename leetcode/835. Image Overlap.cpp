class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int best = 0;
        for (int dy = -n + 1; dy < n; dy++) {
            for (int dx = -n + 1; dx < n; dx++) {

                int ones = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int r2 = i + dy;
                        int c2 = j + dx;

                        if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < n) {
                            if (img1[i][j] == 1 && img2[r2][c2] == 1) {
                                ones++;
                            }
                        }
                    }
                }
                best = max(best, ones);
            } 
        }

        return best;
    }
};