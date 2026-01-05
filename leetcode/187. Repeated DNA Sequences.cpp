class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        unordered_map<string, int> map;

        for (int i = 0; i < s.size() - 9; i++) {
            string current = s.substr(i, 10);
            map[current]++;
        }

        set<string> result;
        vector<string> resultArr;

        for (auto item : map) {
            if (item.second > 1) 
                result.insert(item.first);
        }

        for (auto item : result) {
            resultArr.push_back(item);
        }

        return resultArr;
    }
};