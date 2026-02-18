class Solution {
public:
    // {expression, value}
    unordered_map<string, vector<int>> memo;

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*';
    }

    int applyOp(char op, int x, int y) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        return x * y;
    }

    vector<int> divideAndConquer(string& ex, int start, int end) {
        string pattern = ex.substr(start, end - start + 1);
        if (memo.count(pattern)) return memo[pattern];

        vector<int> result;
        for (int i = start; i <= end; i++) {
            if (isOperator(ex[i])) {
                vector<int> left = divideAndConquer(ex, start, i - 1);
                vector<int> right = divideAndConquer(ex, i + 1, end);

                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        result.push_back(applyOp(ex[i], left[l], right[r]));
                    }
                }
            }
        }

        if (result.empty()) {
            return memo[pattern] = {stoi(pattern)};
        }
        return memo[pattern] = result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return divideAndConquer(expression, 0, expression.size() - 1);
    }
};