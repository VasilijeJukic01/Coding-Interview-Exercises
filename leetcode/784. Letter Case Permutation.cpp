class Solution {
public:
    vector<string> result;

    bool isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }

    char toggle(char ch) {
        return ch ^ 32;
    }

    void solve(string& s, string& curr, int i) {
        if (curr.size() == s.size()) {
            result.push_back(curr);
            return;
        }

        // Normal
        curr += s[i];
        solve(s, curr, i + 1);
        // Backtrack
        curr.pop_back();

        // Toggle
        if (isNum(s[i])) return;
        curr += toggle(s[i]);
        solve(s, curr, i + 1);
        // Backtrack
        curr.pop_back();
    }

    vector<string> letterCasePermutation(string s) {
        string curr;
        solve(s, curr, 0);
        return result;
    }
};