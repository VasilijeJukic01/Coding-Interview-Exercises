class Solution {
public:
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int applyOperation(int x, int y, string op) {
        if (op == "+") return x + y;
        else if (op == "-") return x - y;
        else if (op == "*") return x * y;
        else if (op == "/") return x / y;

        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                s.push(applyOperation(x, y, tokens[i]));
            }
            else s.push(stoi(tokens[i]));
        }

        return s.top();
    }
};