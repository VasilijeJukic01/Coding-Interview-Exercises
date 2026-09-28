class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int maxValid = 0;
        stack<int> st;

        int currLen = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(currLen);
                currLen = 0;
            }
            else {
                if (st.empty()) {
                    maxValid = max(maxValid, currLen);
                    currLen = 0;
                    continue;
                }

                int prevLen = st.top();
                st.pop();
                currLen += prevLen + 2;

                maxValid = max(maxValid, currLen);
            }
        }

        return maxValid;
    }
};