class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for (int i = 0; i < s.size(); i++) {
            map1[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            map2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) return false;
        }

        return true;
    }
};