class Solution {
public:
    bool isAlpha(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

    char toUpper(char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch;
        return ch - 32;
    }

    char toLower(char ch) {
        if (ch >= 'a' && ch <= 'z') return ch;
        return ch + 32;
    }

    string generateTag(string caption) {
        stringstream ss;
        ss << "#";

        for (int i = 0; i < caption.size(); i++) {
            if (isAlpha(caption[i])) {
                caption[i] = toLower(caption[i]);
            }
        }

        bool toggle = false;
        int count = 1;
        for (int i = 0; i < caption.size(); i++) {
            if (caption[i] == 32 && count != 1) toggle = true;
            else if (isAlpha(caption[i])) {
                ss << (toggle ? toUpper(caption[i]) : caption[i]);
                toggle = false;
                count++;
            }

            if (count == 100) break;
        }

        return ss.str();
    }
};