class Solution {
public:
    int bubbleUp(vector<int>& zeros, int from, int to) {
        int swaps = 0;
        for (int i = from; i > to; i--) {
            swap(zeros[i], zeros[i-1]);
            swaps++;
        }

        return swaps;
    }

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros;

        for (int i = 0; i < n; i++) {
            int zeroCount = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) zeroCount++;
                else break;
            }
            zeros.push_back(zeroCount);
        }

        int swaps = 0;
        for (int i = 0; i < n - 1; i++) {
            int need = n - i - 1;

            bool found = false;
            for (int j = i; j < n; j++) {
                if (zeros[j] >= need) {
                    swaps += bubbleUp(zeros, j, i);
                    found = true;
                    break;
                }
            }
            if (found == false) return -1;
        }

        return swaps;
    }
};