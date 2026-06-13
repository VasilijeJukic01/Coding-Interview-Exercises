class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (auto& word : words) {
            int weight = 0;
            for (int i = 0; i < word.size(); i++) {
                weight += weights[word[i] - 'a'];
            }
            result += ('z' - (weight % 26));
        }

        return result;
    }
};