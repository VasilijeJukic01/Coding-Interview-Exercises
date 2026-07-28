class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> map(26, 0);
        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a']++;
        }

        string odd = "";
        for (int i = 0; i < 26; i++) {
            if (map[i] & 1) {
                odd += (i + 'a');
                break;
            }
        }

        string forward = "";
        for (int i = 0; i < 26; i++) {
            int count = map[i] / 2;
            for (int k = 0; k < count; k++) {
                forward += (i + 'a');
            }
        }

        string backward = forward;
        reverse(backward.begin(), backward.end());

        return forward + odd + backward;
    }
};