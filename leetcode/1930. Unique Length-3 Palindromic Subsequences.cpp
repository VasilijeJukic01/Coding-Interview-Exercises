class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> map;
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            map[s[i]].push_back(i);
        }

        for (int i = 'a'; i <= 'z'; i++) {
            if (map[i].size() < 2) continue;

            int lb = map[i].front();
            int ub = map[i].back();

            for (int j = 'a'; j <= 'z'; j++) {
                if (map[j].size() == 0) continue;

                if (i == j && map[i].size() > 2) total++;
                else if (i != j) {
                    for (int k : map[j]) {
                        if (k > lb && k < ub) {
                            total++;
                            break;
                        }
                    }
                }
            }
        }

        return total;
    }
};