class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int updateMask(int mask, char ch) {
        if (ch == 'a') return mask ^ (1 << 4);
        if (ch == 'e') return mask ^ (1 << 3);
        if (ch == 'i') return mask ^ (1 << 2);
        if (ch == 'o') return mask ^ (1 << 1);
        return mask ^ 1;
    }
public:
    int findTheLongestSubstring(string s) {
        int longest = 0;

        // {mask, index}
        unordered_map<int, int> map;
        map[0] = -1;

        // mask [1=a 1=e 1=i 1=o 1=u]
        int mask = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                mask = updateMask(mask, s[i]);
            }

            if (map.count(mask)) {
                longest = max(longest, i - map[mask]);
            }
            else map[mask] = i;
        }

        return longest;
    }
};