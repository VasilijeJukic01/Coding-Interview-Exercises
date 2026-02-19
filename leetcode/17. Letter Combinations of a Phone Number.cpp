class Solution {
public:
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> result;

    void solve(string digits, string& curr, int index) {
        if (curr.size() == digits.size()) {
            result.push_back(curr);
            return;
        }

        auto& values = map[digits[index]];
        for (int i = 0; i < values.size(); i++) {
            curr += values[i];
            solve(digits, curr, index + 1);
            // Backtrack
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string curr;
        solve(digits, curr, 0);

        return result;
    }
};