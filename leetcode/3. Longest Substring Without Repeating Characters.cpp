class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> map;
        int left = 0;

        int best = 0;
        for (int right = 0; right < s.size(); right++) {
            map[s[right]]++;
            while (map[s[right]] > 1) {
                map[s[left]]--;
                left++;
            }
            best = max(best, right - left + 1);
        }

        return best;
    }
};