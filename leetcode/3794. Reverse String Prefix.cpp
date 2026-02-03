class Solution {
public:
    string reversePrefix(string s, int k) {
        for (int i = 0, j = k - 1; i <= j; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
};