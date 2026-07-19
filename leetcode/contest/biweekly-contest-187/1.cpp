class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string first = "";
        string second = "";
        string third = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == y) first += y;
            else if (s[i] == x) third += x;
            else second += s[i];
        }
        
        return first + second + third;
    }
};