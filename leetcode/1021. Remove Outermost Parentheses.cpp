class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        stringstream ss;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (!st.empty()) ss << "(";
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                st.pop();
                if (st.empty()) continue;
                ss << ")";
            }
        }

        return ss.str();
    }
};