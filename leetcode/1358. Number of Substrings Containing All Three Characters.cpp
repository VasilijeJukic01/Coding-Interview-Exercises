class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> map;
        
        int total = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            map[s[right]]++;
            while (map.size() == 3) {
                total += (s.size() - right);
                map[s[left]]--;
                if (map[s[left]] == 0) {
                    map.erase(s[left]);
                }
                left++;
            }
        }

        return total;
    }
};