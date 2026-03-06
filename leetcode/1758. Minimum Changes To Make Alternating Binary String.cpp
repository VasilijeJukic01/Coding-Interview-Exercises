class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;

        int currBit = 0;
        if (s[0] == '1') count1++;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == currBit + '0') {
                count1++;
                currBit = 1 - currBit;
            }
            else currBit = s[i] - '0';
        }

        currBit = 1;
        if (s[0] == '0') count2++;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == currBit + '0') {
                count2++;
                currBit = 1 - currBit;
            }
            else currBit = s[i] - '0';
        }

        return min(count1, count2);
    }
};