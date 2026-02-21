class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;

        for (int k = 0; k < words.size(); k++) {
            for (int i = 0; i < words[k].size(); i++) {
                if (words[k][i] == x) {
                    indices.push_back(k);
                    break;
                }
            }
        }

        return indices;
    }
};