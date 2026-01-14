class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int sPtr = 0;

        for (int tPtr = 0; tPtr < t.size(); tPtr++) {
            if (t[tPtr] == s[sPtr]) {
                sPtr++;
                if (sPtr == s.size()) return true;
            }
        }

        return false;
    }
};