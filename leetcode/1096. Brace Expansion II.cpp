class Solution {
    bool isLetter(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isNextMatch(char next, char match) {
        return next == match || isLetter(next);
    }

    void combine(stack<set<string>>& values, stack<char>& ops) {
        set<string> val1 = values.top();
        values.pop();
        set<string> val2 = values.top();
        values.pop();

        char op = ops.top();
        if (op == '*') {
            set<string> mult;
            for (auto& x : val2) {
                for (auto& y : val1) {
                    mult.insert({x + y});
                }
            }
            values.push(mult);
        }
        else if (op == '+') {
            val2.insert(val1.begin(), val1.end());
            values.push(val2);
        }
        ops.pop();
    }
public:
    vector<string> braceExpansionII(string expression) {
        int n = expression.size();
        string exp;

        for (int i = 0; i < n; i++) {
            if (expression[i] == '{') exp += '(';
            else if (expression[i] == '}') {
                exp += ')';
                if (i < n - 1 && isNextMatch(expression[i + 1], '{')) {
                    exp += '*';
                }
            }
            else if (expression[i] == ',') exp += '+';
            else {
                exp += expression[i];
                if (i < n - 1 && isNextMatch(expression[i + 1], '{')) {
                    exp += '*';
                }
            }
        }

        stack<set<string>> values;
        stack<char> ops;
        for (int i = 0; i < exp.size(); i++) {
            if (exp[i] == '(') ops.push('(');
            else if (exp[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    combine(values, ops);
                }
                ops.pop();
            }
            else if (exp[i] == '+') {
                while (!ops.empty() && ops.top() != '(') {
                    combine(values, ops);
                }
                ops.push('+');
            }
            else if (exp[i] == '*') {
                while (!ops.empty() && ops.top() == '*') {
                    combine(values, ops);
                }
                ops.push('*');
            }
            else values.push({string(1, exp[i])});
        }

        while (!ops.empty()) {
            combine(values, ops);
        }

        set<string>& resultSet = values.top();
        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }
};