class Solution {
public:
    string decodeString(string s) {
        stack<int> kStack;
        stack<string> sStack;

        int num = 0;
        string curr = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                kStack.push(num);
                sStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (s[i] == ']') {
                int k = kStack.top(); 
                kStack.pop();
                string prev = sStack.top(); 
                sStack.pop();

                for (int j = 0; j < k; j++) {
                    prev += curr;
                }
                
                curr = prev;
            }
            else curr += s[i];
        }

        return curr;
    }
};