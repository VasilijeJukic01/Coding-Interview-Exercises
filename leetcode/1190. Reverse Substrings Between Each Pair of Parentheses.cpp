class Solution {
    using p = pair<string, int>;
public:
    string reverseParentheses(string s) {
        stack<p> st;
        int brackets = 0;

        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (!curr.empty()) {
                    if (brackets & 1) reverse(curr.begin(), curr.end());
                    st.push({curr, brackets});
                }
                brackets++;
                curr = "";
            }
            else if (s[i] == ')') {
                if (!curr.empty()) {
                    if (brackets & 1) reverse(curr.begin(), curr.end());
                    st.push({curr, brackets});
                    curr = "";
                }

                stack<string> helper;
                string res = "";
                if (brackets & 1) {
                    while (!st.empty() && st.top().second >= brackets) {
                        res += st.top().first;
                        st.pop();
                    }
                }
                else {
                    stack<string> helper;
                    while (!st.empty() && st.top().second >= brackets) {
                        helper.push(st.top().first);
                        st.pop();
                    }
                    while (!helper.empty()) {
                        res += helper.top();
                        helper.pop();
                    }
                }
                brackets--;
                if (!res.empty()) st.push({res, brackets});
            }
            else curr += s[i];
        }

        if (!curr.empty()) st.push({curr, brackets});
        string result = "";
        while (!st.empty()) {
            result = st.top().first + result;
            st.pop();
        }
        return result;
    }
};