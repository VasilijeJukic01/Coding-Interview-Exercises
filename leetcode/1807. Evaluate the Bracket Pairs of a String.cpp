class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (auto& data : knowledge) {
            map[data[0]] = data[1];
        }

        stringstream ss;
        
        bool brackets = false;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                brackets = true;
                start = i + 1;
            }
            else if (s[i] == ')') {
                brackets = false;
                end = i - 1;
                string key = s.substr(start, end - start + 1);
                if (map.count(key)) ss << map[key];
                else ss << "?";
            }
            else if (!brackets) {
                ss << s[i];
            }
        }

        return ss.str();
    }
};