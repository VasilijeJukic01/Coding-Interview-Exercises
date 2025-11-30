class Solution {
public:
    string clearDigits(string s) {
        deque<char> dq;

        string result;

        for (int i = 0; i < s.size(); i++) {
            if (!dq.empty() && s[i] >= '0' && s[i] <= '9') dq.pop_back();
            else dq.push_back(s[i]);
        }

        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }

        return result;
    }
};