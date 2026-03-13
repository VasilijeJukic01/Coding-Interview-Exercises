class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    currRow[j] = 1 + nextRow[j + 1];
                }
                else currRow[j] = max(nextRow[j], currRow[j + 1]);
            }
            nextRow = currRow;
        }

        return currRow[0];
    }
};