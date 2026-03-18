class Solution {
public:
    void expand(string& s, int& start, int& maxLen, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            expand(s, start, maxLen, i, i);
            expand(s, start, maxLen, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};