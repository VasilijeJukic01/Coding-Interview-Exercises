class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p = 0;

        for (int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && popped[p] == s.top()) {
                p++;
                s.pop();
            }
        }

        return s.empty();
    }
};