class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> q;
        stringstream ss;

        for (int i = 0; i < s.size(); i++) {
            if (!q.empty() && s[i] == q.back()) {
                q.pop_back();
            }
            else q.push_back(s[i]);
        }

        while (!q.empty()) {
            ss << q.front();
            q.pop_front();
        }

        return ss.str();
    }
};