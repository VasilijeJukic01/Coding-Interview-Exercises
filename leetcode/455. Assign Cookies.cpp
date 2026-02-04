class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gIdx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (gIdx == g.size()) break;
            if (s[i] >= g[gIdx]) gIdx++;
        }

        return gIdx;
    }
};