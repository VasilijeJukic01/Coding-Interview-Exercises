class Solution {
public:
    void reverse(string& str, int s, int e) {
        for (int i = s, j = e; i <= j; i++, j--) {
            swap(str[i], str[j]);
        }
    } 

    string reverseWords(string s) {
        s += ' ';
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                end = i - 1;
                reverse(s, start, end);
                start = i + 1;
            }
        }
        s.pop_back();

        return s;
    }
};