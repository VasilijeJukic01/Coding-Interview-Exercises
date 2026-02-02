class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            if (s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;
        }
        return s;
    }
};