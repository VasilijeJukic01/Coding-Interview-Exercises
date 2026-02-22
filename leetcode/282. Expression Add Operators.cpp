class Solution {
public:
    vector<string> result;

    char selectOp(int i) {
        if (i == 0) return '+';
        if (i == 1) return '-';
        return '*';
    }

    void solve(string& num, int t, int i, long long sum, long long prev, string& curr) {
        if (i == num.size() && sum == t) {
            result.push_back(curr);
            return;
        }

        for (int j = i; j < num.size(); j++) {
            // Skip leading zeros
            if (num[i] == '0' && j > i) break; 

            string part = num.substr(i, j - i + 1);
            long long currVal = stoll(part);

            // First number
            if (i == 0) {
                curr += part;
                solve(num, t, j + 1, currVal, currVal, curr);
                // Backtrack
                for (int k = 0; k < part.length(); k++) {
                    curr.pop_back();
                }
            }
            // Not first number
            else {
                for (int opIdx = 0; opIdx < 3; opIdx++) {
                    char op = selectOp(opIdx);
                    curr += op;
                    curr += part;

                    long long nextSum = 0;
                    long long nextPrev = 0;

                    if (op == '+') {
                        nextSum = sum + currVal;
                        nextPrev = currVal;
                    }
                     else if (op == '-') {
                        nextSum = sum - currVal;
                        nextPrev = -currVal;
                    } 
                    else if (op == '*') {
                        nextSum = sum - prev + (prev * currVal);
                        nextPrev = prev * currVal;
                    }

                    solve(num, t, j + 1, nextSum, nextPrev, curr);

                    // Backtrack
                    for (int k = 0; k < part.length(); k++) {
                        curr.pop_back();
                    }
                    curr.pop_back();
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string curr;
        solve(num, target, 0, 0, 0, curr);
        return result;
    }
};