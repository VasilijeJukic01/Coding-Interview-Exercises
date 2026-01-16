class Solution {
public:
    bool checkPermutation(vector<int>& map1, vector<int>& map2) {
        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            map1[s1[i] - 'a']++;
        }

        int k = s1.size();
        for (int i = 0; i < k; i++) {
            map2[s2[i] - 'a']++;
        }

        if (checkPermutation(map1, map2)) return true;

        for (int i = k; i < s2.size(); i++) {
            map2[s2[i] - 'a']++;
            map2[s2[i - k] - 'a']--;
            if (checkPermutation(map1, map2)) return true;
        }

        return false;
    }
};