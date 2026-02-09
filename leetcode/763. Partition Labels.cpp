class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> map(26, 0);
        unordered_set<char> remaining;

        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a']++;
        }

        vector<int> result;
        int counter = 1;
        for (int i = 0; i < s.size(); i++) {
            remaining.insert(s[i]);
            map[s[i] - 'a']--;

            if (map[s[i] - 'a'] == 0) {
                remaining.erase(s[i]);
            }

            if (remaining.size() == 0) {
                result.push_back(counter);
                counter = 0;
            }
            counter++;
        }

        return result;
    }
};