class Solution {
public:
    bool checkOnesSegment(string s) {
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '1') break;
        }

        while (i < s.size() && s[i] == '1') {
            i++;
        }

        for (; i < s.size(); i++) {
            if (s[i] == '1') return false;
        }

        return true;
    }
};