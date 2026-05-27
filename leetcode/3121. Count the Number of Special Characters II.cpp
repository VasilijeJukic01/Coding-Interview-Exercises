class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastIdx(26, -1);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                lastIdx[word[i] - 'a'] = i;
            }
        }

        vector<int> firstIdx(26, -1);
        for (int i = word.size() - 1; i >= 0; i--) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                firstIdx[word[i] - 'A'] = i;
            }
        }

        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (firstIdx[i] == -1 || lastIdx[i] == -1) continue;
            if (firstIdx[i] > lastIdx[i]) total++;
        }

        return total;
    }
};