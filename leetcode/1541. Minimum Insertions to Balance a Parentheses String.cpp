class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int insertions = 0;

        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open++;
            else {
                if (i < n - 1 && s[i + 1] == ')') {
                    if (open > 0) open--;
                    else insertions++;
                    i++;
                }
                else {
                    if (open > 0) {
                        open--;
                        insertions++;
                    }
                    else insertions += 2;
                }
            }
        }

        if (open > 0) insertions += (open * 2); 
        
        return insertions;
    }
};