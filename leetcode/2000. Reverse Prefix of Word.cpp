class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                for (int m = 0, n = i; m < n; m++, n--) {
                    swap(word[m], word[n]);
                }
                break;
            }
        }

        return word;
    }
};