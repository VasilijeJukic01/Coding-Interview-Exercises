class Solution {
public:
    using table = vector<vector<int>>;

    int solve(table& memo, string& s1, string& s2, int i, int j) {
        if (i == s1.size() && j == s2.size()) return 0;
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;

        if (memo[i][j] != -1) return memo[i][j];

        int optionA = INT_MAX;
        int optionB = INT_MAX, optionC = INT_MAX;
        if (s1[i] == s2[j]) {
            optionA = 1 + solve(memo, s1, s2, i + 1, j + 1);
        }
        else {
            optionB = 1 + solve(memo, s1, s2, i + 1, j);
            optionC = 1 + solve(memo, s1, s2, i, j + 1);
        }

        return memo[i][j] = min({optionA, optionB, optionC});
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        string result = "";

        table memo(m, vector<int>(n, -1));
        solve(memo, str1, str2, 0, 0);

        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j]) {
                result += str1[i];
                i++;
                j++;
            }
            else {
                int costI = solve(memo, str1, str2, i + 1, j);
                int costJ = solve(memo, str1, str2, i, j + 1);
                if (costI < costJ) {
                    result += str1[i];
                    i++;
                }
                else {
                    result += str2[j];
                    j++;
                }
            }
        }

        if (i == str1.size()) result += str2.substr(j);
        if (j == str2.size()) result += str1.substr(i);

        return result;
    }
};