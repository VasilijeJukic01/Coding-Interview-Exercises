class Solution {
public:
    bool isAlpha(char ch) {
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= '0' && ch <= '9') return true;
        return false;
    }

    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < s.size() - 1 && !isAlpha(tolower(s[i]))) i++;
            while (j >= 1 && !isAlpha(tolower(s[j]))) j--;
            if (i >= j) return true;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};