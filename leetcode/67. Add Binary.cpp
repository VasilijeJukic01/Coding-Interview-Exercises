class Solution {
public:
    string addBinary(string a, string b) {
        string& smaller = a.size() < b.size() ? a : b;
        string& bigger = a.size() >= b.size() ? a : b;

        reverse(smaller.begin(), smaller.end());
        reverse(bigger.begin(), bigger.end());

        int rmd = 0;
        int i;
        for (i = 0; i < smaller.size(); i++) {
            int x = smaller[i] - '0';
            int y = bigger[i] - '0';

            bigger[i] = (x ^ y ^ rmd) + '0';
            rmd = (x & y) | (x & rmd) | (y & rmd);
        }

        while (i < bigger.size() && rmd) {
            int x = bigger[i] - '0';
            bigger[i] = (x ^ rmd) + '0';
            rmd = x & rmd;
            i++;
        }

        if (rmd) bigger.push_back('1');
        reverse(bigger.begin(), bigger.end());

        return bigger;
    }
};