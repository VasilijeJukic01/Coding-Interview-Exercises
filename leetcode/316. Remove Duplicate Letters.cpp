class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> map(26, 0);
        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a'] = i;
        }

        deque<char> dq;
        vector<bool> seen(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) continue;

            while (!dq.empty() && dq.back() > s[i] && map[dq.back() - 'a'] > i) {
                seen[dq.back() - 'a'] = false;
                dq.pop_back();
            }

            dq.push_back(s[i]);
            seen[s[i] - 'a'] = true;
        }

        string result = "";
        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }

        return result;
    }
};