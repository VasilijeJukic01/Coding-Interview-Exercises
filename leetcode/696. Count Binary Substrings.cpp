class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;

        int prev = s[0];
        int counter = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != prev) {
                counts.push_back(counter);
                counter = 1;
            }
            else counter++;
            prev = s[i];
        }
        counts.push_back(counter);

        int total = 0;
        for (int i = 0; i < counts.size() - 1; i++) {
            total += min(counts[i], counts[i + 1]);
        }

        return total;
    }
};