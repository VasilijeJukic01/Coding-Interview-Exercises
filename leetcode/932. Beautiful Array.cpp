class Solution {
public:
    unordered_map<int, vector<int>> memo;

    vector<int> beautifulArray(int n) {
        if (memo.count(n)) return memo[n];
        if (n == 1) return memo[n] = {1};

        vector<int> left = beautifulArray((n + 1) / 2);
        vector<int> right = beautifulArray(n / 2);

        vector<int> merge;
        for (int i = 0; i < left.size(); i++) {
            merge.push_back(2 * left[i] - 1);
        }
        for (int i = 0; i < right.size(); i++) {
            merge.push_back(2 * right[i]);
        }

        return memo[n] = merge;
    }
};