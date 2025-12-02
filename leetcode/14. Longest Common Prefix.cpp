class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string best = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int len = min(best.size(), strs[i].size());
            string curr = "";
            for (int j = 0; j < len; j++) {
                if (strs[i][j] != best[j]) break;
                curr += strs[i][j];
            }
            best = curr;
        }

        return best;
    }
};