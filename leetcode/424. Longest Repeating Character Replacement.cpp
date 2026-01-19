class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26, 0);

        int best = 0;
        int left = 0;
        int maxFreq = 0;
        for (int right = 0; right < s.size(); right++) {
            map[s[right] - 'A']++;
            maxFreq = max(maxFreq, map[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                map[s[left] - 'A']--;
                left++;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};