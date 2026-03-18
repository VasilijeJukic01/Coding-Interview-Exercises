class Solution {
public:
    void expand(string& s, int& counter, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            counter++;
            l--;
            r++;
        }
    }

    int countSubstrings(string s) {
        int counter = 0;
        
        for (int i = 0; i < s.size(); i++) {
            expand(s, counter, i, i);
            expand(s, counter, i, i + 1);
        }

        return counter;
    }
};