class Solution {
public:
    bool isNumber(string s) {
        vector<vector<int>> dfa(9, vector<int>(128, -1));
        unordered_set<int> finish = {2, 3, 4, 7};

        dfa[0]['.'] = 8;
        dfa[0]['+'] = dfa[0]['-'] = 1;
        dfa[1]['.'] = 8;
        dfa[2]['.'] = 3;
        dfa[2]['e'] = dfa[2]['E'] = 5;
        dfa[3]['e'] = dfa[3]['E'] = 5;
        dfa[4]['e'] = dfa[4]['E'] = 5;
        dfa[5]['+'] = dfa[5]['-'] = 6;
        for (int i = 0; i <= 9; i++) {
            dfa[0][i + '0'] = 2;
            dfa[1][i + '0'] = 2;
            dfa[8][i + '0'] = 4;
            dfa[2][i + '0'] = 2;
            dfa[3][i + '0'] = 4;
            dfa[4][i + '0'] = 4;
            dfa[5][i + '0'] = 7;
            dfa[6][i + '0'] = 7;
            dfa[7][i + '0'] = 7;
        }

        int curr = 0;
        for (int i = 0; i < s.size(); i++) {
            int next = dfa[curr][s[i]];
            if (next == -1) return false;
            curr = next;
        }

        if (finish.find(curr) != finish.end()) return true;
        return false;
    }
};