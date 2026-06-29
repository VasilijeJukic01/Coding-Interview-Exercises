class Solution {
    using table = vector<vector<vector<int>>>;

    int solve(table& memo, unordered_set<int>& available, string &num, int i, bool tight, bool leadZero) {
        if (i == num.size()) return 1;

        if (memo[i][tight][leadZero] != -1) {
            return memo[i][tight][leadZero];
        }

        int total = 0;
        int bound = tight ? num[i] - '0' : 9;
        for (int k = 0; k <= bound; k++) {
            if (leadZero) {
                if (k != 0 && available.count(k) == 0) {
                    continue;
                } 
            }
            else if (available.count(k) == 0) continue;

            bool tightP = (tight && (k == bound));
            bool leadZeroP = (leadZero && (k == 0));

            total += solve(memo, available, num, i + 1, tightP, leadZeroP);
        }

        return memo[i][tight][leadZero] = total;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        unordered_set<int> available;

        for (auto& dig : digits) {
            available.insert(dig[0] - '0');
        }

        string num = to_string(n);
        int len = num.size();

        // [len] x [2] x [2]
        table memo(len, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(memo, available, num, 0, true, true) - 1;
    }
};