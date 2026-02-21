class Solution {
public:
    vector<string> result;

    bool isPartValid(string& part) {
        if (part.size() > 1 && part[0] == '0') return false;
        if (stoi(part) > 255) return false;
        return true;
    }

    void solve(string& s, string& curr, int index, int dots) {
        if (index == s.size() && dots == 4) {
            curr.pop_back();
            result.push_back(curr);
            curr += ".";
            return;
        }
        if (dots == 4 || index == s.size()) return;

        int len = s.size();
        int n = min(len, index + 3);

        for (int i = index; i < n; i++) {
            string part = s.substr(index, i - index + 1);
            if (!isPartValid(part)) break;

            curr += part;
            curr += '.';
            solve(s, curr, i + 1, dots + 1);
            // Backtrack
            for (int k = 0; k < part.length() + 1; k++) {
                curr.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return {};

        string curr;
        solve(s, curr, 0, 0);
        return result;
    }
};