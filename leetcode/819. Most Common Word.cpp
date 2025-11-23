class Solution {
public:
     int isSpecial(char c) {
        if (c == '"' || c == '\'') return 2;
        if (c == '.' || c == '?' || c == '!' || c == ';' || c == ',' || c == ' ') return 1;
        return 0;
    }

    bool isBanned(const string& word, unordered_set<string>& banned) {
        return banned.find(word) != banned.end();
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> wordCount;

        string word = "";
        for (int i = 0; i < paragraph.size(); i++) {
            // Quote skip
            if (isSpecial(paragraph[i]) == 2) continue;
            // End of word
            if (isSpecial(paragraph[i]) == 1) {
                if (!word.empty()) {
                    wordCount[word]++;
                    word = "";
                }
            }
            else word += tolower(paragraph[i]);
        }

        if (!word.empty()) wordCount[word]++;

        string result = "";
        int maxCount = 0;
        for (auto entry : wordCount) {
            if (!isBanned(entry.first, bannedSet) && entry.second > maxCount) {
                maxCount = entry.second;
                result = entry.first;
            }
        }

        return result;
    }
};