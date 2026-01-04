class Solution {
public:
    string vectorize(string& word) {
        string v(26, 0);
        for (int i = 0; i < word.size(); i++) {
            v[word[i] - 'a']++;
        }

        return v;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string& s : strs) {
            map[vectorize(s)].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& [_, value] : map) {
            result.push_back(value);
        }

        return result;
    }
};