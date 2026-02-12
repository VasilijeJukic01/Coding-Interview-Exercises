class Solution {
public:
    int longestBalanced(string s) {
        vector<int> map(26, 0);

        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                map[s[j] - 'a']++;

                int prev = 0;
                bool valid = true;
                for (int k = 0; k < 26; k++) {
                    if (map[k] != 0) {
                        if (prev != 0 && prev != map[k]) {
                            valid = false;
                        }
                        prev = map[k];
                    }
                }
                if (valid) longest = max(longest, j - i + 1);
            }
            fill(map.begin(), map.end(), 0);
        }

        return longest;
    }
};