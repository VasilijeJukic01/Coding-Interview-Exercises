class Solution {
public:
    string convertToTitle(int columnNumber) {
        string col = "";

        while (columnNumber) {
            columnNumber--;
            int r = columnNumber % 26;
            col += 'A' + r;

            columnNumber /= 26;
        }

        reverse(col.begin(), col.end());

        return col;
    }
};