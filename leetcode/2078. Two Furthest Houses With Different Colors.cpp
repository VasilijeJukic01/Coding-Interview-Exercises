class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        for (int r = n - 1; r >= 0; r--) {
            if (colors[0] != colors[r]) {
                maxDist = max(maxDist, r);
                break;
            }
        }

        for (int l = 0; l < n; l++) {
            if (colors[l] != colors[n - 1]) {
                maxDist = max(maxDist, n - l - 1);
                break;
            }
        }

        return maxDist;
    }
};