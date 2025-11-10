class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int number = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 && map[s[i]] < map[s[i+1]]) {
                number += map[s[i+1]] - map[s[i]];
                i++;
            }
            else number += map[s[i]];
        }

        return number; 
    }
};