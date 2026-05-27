class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> map(26);

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z') {
                map[ch - 'a'] = true;
            }
        }

        int total = 0;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch >= 'A' && ch <= 'Z') {
                if (map[ch + 32 - 'a']) {
                    map[ch + 32 - 'a'] = false;
                    total++;
                }
            }
        }

        return total;
    }
};