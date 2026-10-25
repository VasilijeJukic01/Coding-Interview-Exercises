class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();

        int total = 0;
        for (int j = 0; j < n - 1; j++) {
            vector<int> leftMap(27, 0);
            vector<int> rightMap(27, 0);

            int leftUnique = 0;
            vector<bool> seenL(26, 0);
            for (int i = j; i >= 0; i--) {
                if (!seenL[s[i] - 'a']) {
                    seenL[s[i] - 'a'] = true;
                    leftUnique++;
                }
                leftMap[leftUnique]++;
            }

            int rightUnique = 0;
            vector<bool> seenR(26, 0);
            for (int k = j + 1; k < n; k++) {
                if (!seenR[s[k] - 'a']) {
                    seenR[s[k] - 'a'] = true;
                    rightUnique++;
                }
                rightMap[rightUnique]++;
            }

            for (int c = 1; c <= 26; c++) {
                total += leftMap[c] * rightMap[c];
            }
        }

        return total;
    }
};