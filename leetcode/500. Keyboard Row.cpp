class Solution {
public:

    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch+32;
        return ch;
    }

    vector<string> findWords(vector<string>& words) {
        string firstRow = "qwertyuiop";
        string secondRow = "asdfghjkl";
        string thirdRow = "zxcvbnm";

        unordered_map<char, int> map;
        vector<string> result;

        for (char c : firstRow) map[c] = 1;
        for (char c : secondRow) map[c] = 2;
        for (char c : thirdRow) map[c] = 3;

        for (string w : words) {
            int row = map[toLower(w[0])];
            bool flag = true;
            for (int i = 1; i < w.size(); i++) {
                if (map[toLower(w[i])] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) result.push_back(w);
        }

        return result;
    }
};