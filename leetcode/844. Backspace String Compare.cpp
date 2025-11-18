class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int tPointer = t.size() - 1;
        int sPointer = s.size() - 1;

        int tSlashCount = 0, sSlashCount = 0;
        while (tPointer >= 0 || sPointer >= 0) {

            int sBpCount = 0;
            while (sPointer >= 0 && (s[sPointer] == '#' || sBpCount > 0)) {
                if (s[sPointer] == '#') sBpCount++;
                else sBpCount--;
                sPointer--;
            }

            int tBpCount = 0;
            while (tPointer >= 0 && (t[tPointer] == '#' || tBpCount > 0)) {
                if (t[tPointer] == '#') tBpCount++;
                else tBpCount--;
                tPointer--;
            }

            if (sPointer < 0 || tPointer < 0) {
                return sPointer == tPointer;
            }

            if (s[sPointer] != t[tPointer]) return false;

            sPointer--;
            tPointer--;
        }

        return true;
    }
};