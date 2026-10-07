class Solution {
    using vs = vector<string>;
public:
    void solve(vs& result, string& curr, string& s, int i, int open) {
        if (i == s.size()) {
            if (open == 0) result.push_back(curr);
            return;
        }

        if (open < 0) return;

        if (s[i] != '(' && s[i] != ')') {
            curr += s[i];
            solve(result, curr, s, i + 1, open);
            curr.pop_back();
        }
        else {
            // Skip
            solve(result, curr, s, i + 1, open);
            // Use
            if (s[i] == '(') open++;
            else open--;
            curr += s[i];

            solve(result, curr, s, i + 1, open);

            if (s[i] == '(') open--;
            else open++;
            curr.pop_back();
        }
    }

    vs removeInvalidParentheses(string s) {
        vs result;
        string curr;
        solve(result, curr, s, 0, 0);

        int maxSize = 0;
        for (auto& candidate : result) {
            maxSize = max(maxSize, (int)candidate.size());
        }

        unordered_set<string> filtered;
        for (auto& candidate : result) {
            if (candidate.size() == maxSize) {
                filtered.insert(candidate);
            }
        }

        vs filteredStr(filtered.begin(), filtered.end());

        return filteredStr;
    }
};