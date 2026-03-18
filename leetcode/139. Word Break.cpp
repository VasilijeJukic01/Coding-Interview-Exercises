class Solution {
public:
    bool solve(vector<int>& memo, string& s, int i, vector<string>& dict) {
        if (i == s.size()) return true;

        if (memo[i] != -1) return memo[i];

        for (auto& word : dict) {
            if (i + word.size() > s.size()) continue;

            bool valid = true;
            int index = i;
            for (int k = 0; k < word.size(); k++) {
                if (s[index] != word[k]) {
                    valid = false;
                    break;
                }
                index++;
            }
            if (!valid) continue;
            if (solve(memo, s, index, dict)) return memo[i] = true;
        }

        return memo[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return solve(memo, s, 0, wordDict);
    }
};