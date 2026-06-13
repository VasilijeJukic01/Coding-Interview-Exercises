class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);
        for (int i = 0; i < s.length(); i++) {
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            mapS[s[i]] = i;
            mapT[t[i]] = i;
        }

        return true;
    }
};