class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> s;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") s.pop();
            else if (operations[i] == "D") {
                string x = s.top();
                x = to_string(stoi(x) * 2);
                s.push(x);
            }
            else if (operations[i] == "+") {
                string x = s.top();
                s.pop();
                string y = s.top();
                s.push(x);
                s.push(to_string(stoi(x) + stoi(y)));
            }
            else s.push(operations[i]);
        }

        int result = 0;
        while (!s.empty()) {
            result += stoi(s.top());
            s.pop();
        }

        return result;
    }
};