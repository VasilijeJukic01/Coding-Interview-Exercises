class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int open = 0;
        int prev = 32;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                open--;
                if (prev == '(') score += 1 << open;
            }
            prev = s[i];
        }

        return score;
    }
};