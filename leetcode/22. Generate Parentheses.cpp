class Solution {
public:
    vector<string> result;

    void solve(int n, string& curr, int open, int closed) {
        if (open == n && closed == n) {
            result.push_back(curr);
            return;
        }

        if (open < n) {
            curr += '(';
            solve(n, curr, open + 1, closed);
            // Backtrack
            curr.pop_back();
        }
        if (open > closed && closed < n) {
            curr += ')';
            solve(n, curr, open, closed + 1);
            // Backtrack
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string curr;
        solve(n, curr, 0, 0);
        return result;
    }
};