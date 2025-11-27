class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' ||ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            while (left < s.size() && !isVowel(tolower(s[left]))) left++;
            while (right >= 0 && !isVowel(tolower(s[right]))) right--;

            if (left >= s.size() || right < 0 || left > right) break;

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};