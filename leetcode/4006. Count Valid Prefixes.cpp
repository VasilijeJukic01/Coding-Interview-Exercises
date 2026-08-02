class Solution {
public:
    int countValidPrefixes(string s) {
        int counter = 0;
        int diff = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') diff++;
            else diff--;

            if (abs(diff) <= 1) counter++;
        }

        return counter;
    }
};