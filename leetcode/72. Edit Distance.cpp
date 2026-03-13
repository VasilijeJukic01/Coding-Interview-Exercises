class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int j = 0; j <= n; j++) {
            nextRow[j] = n - j;
        }

        for (int i = m - 1; i >= 0; i--) {
            currRow[n] = m - i;
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    currRow[j] = nextRow[j + 1];
                }
                else {
                    int insert = currRow[j + 1];
                    int replace = nextRow[j + 1];
                    int remove = nextRow[j];
                    currRow[j] = 1 + min({insert, replace, remove});
                }
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
};