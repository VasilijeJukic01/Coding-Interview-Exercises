class Solution {
public:
    void solve(vector<int> &res, string &num, int i, bool tight, bool leadZero, int prev, int curr, int minVal) {
        if (i == num.size()) {
            if (!leadZero && curr >= minVal) {
                res.push_back(curr);
            }
            return;
        }

        int ub = tight ? num[i] - '0' : 9;
        for (int k = 0; k <= ub; k++) {
            bool tightP = (tight && (k == ub));
            bool leadZeroP = (leadZero && (k == 0));
            
            if (leadZeroP) {
                solve(res, num, i + 1, tightP, leadZeroP, 0, 0, minVal);
            }
            // First digit
            else if (leadZero) {
                solve(res, num, i + 1, tightP, leadZeroP, k, k, minVal);
            }
            else {
                if (k == prev + 1) {
                    solve(res, num, i + 1, tightP, leadZeroP, k, curr * 10 + k, minVal);
                }
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        string num2 = to_string(high);
        vector<int> res;

        solve(res, num2, 0, true, true, 0, 0, low);
        sort(res.begin(), res.end());

        return res;
    }
};