class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i <= j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void trim(string& s, int n) {
        int write = 0;

        bool started = false;
        for (int read = 0; read < n; read++) {
            if (s[read] != ' ') {
                started = true;
                s[write++] = s[read];
            }
            else if (s[read] == ' ' && started) {
                if (s[read - 1] != ' ') {
                    s[write++] = s[read];
                }
            }
        }

        for (int i = write - 1; i >= 0; i--) {
            if (s[i] == ' ') write--;
            else break;
        }

        s.resize(write);
    }

    string reverseWords(string s) {
        trim(s, s.size());

        int n = s.size();
        reverse(s, 0, n - 1);

        int start = 0, end;
        for (int i = 0; i < s.size(); i++) {
            if (i < n - 1) {
                if (s[i] == ' ' && s[i + 1] != ' ') {
                    end = i - 1;
                    reverse(s, start, end);
                    start = i + 1;
                }
            }
        }

        reverse(s, start, n-1);

        return s;
    }
};