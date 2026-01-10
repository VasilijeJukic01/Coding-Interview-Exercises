class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> map(26, 0);

        for (int i = 0; i < text.size(); i++) {
            map[text[i] - 'a']++;
        }

        string target = "balloon";
        int total = 0;
        for (int i = 0; i < text.size() / 7; i++) {
            for (int j = 0; j < target.size(); j++) {
                if (map[target[j] - 'a'] == 0) return total;
                map[target[j] - 'a']--;
            }
            total++;
        }

        return total;
    }
};