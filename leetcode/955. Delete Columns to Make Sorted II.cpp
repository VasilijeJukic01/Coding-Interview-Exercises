class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        
        // If columns are sorted
        vector<bool> cache(n, false);
        int total = 0;

        for (int j = 0; j < m; j++) {
            int i;
            for (i = 0; i < n - 1; i++) {
                if (!cache[i] && strs[i][j] > strs[i + 1][j]) {
                    total++;
                    break;
                }
            }

            if (i == n - 1) {
                for (int k = 0; k < n - 1; k++) {
                    if (strs[k][j] < strs[k + 1][j]) {
                        cache[k] = true;
                    }
                }
            }
        }

        return total;
    }
};