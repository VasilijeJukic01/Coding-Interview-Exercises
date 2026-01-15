class Solution {
public:
    bool isAnagram(vector<int>& mapP, vector<int>& mapS) {
        for (int i = 0; i < 26; i++) {
            if (mapP[i] != mapS[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> result;

        vector<int> mapP(26, 0);
        for (int i = 0; i < p.size(); i++) {
            mapP[p[i] - 'a']++;
        }

        int k = p.size();
        vector<int> mapS(26, 0);
        for (int i = 0; i < k; i++) {
            mapS[s[i] - 'a']++;
        }

        if (isAnagram(mapP, mapS)) result.push_back(0);

        for (int i = k; i < s.size(); i++) {
            mapS[s[i] - 'a']++;
            mapS[s[i - k] - 'a']--;
            if (isAnagram(mapP, mapS)) {
                result.push_back(i - k + 1);
            }
        }

        return result;
    }
};