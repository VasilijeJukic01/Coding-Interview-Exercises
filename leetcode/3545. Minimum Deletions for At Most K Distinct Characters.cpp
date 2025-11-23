class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> map;
        vector<int> freq;
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }

        for (auto item : map) {
            freq.push_back(item.second);
        }

        sort(freq.begin(), freq.end());

        if (freq.size() <= k) return 0;

        for (int i = 0; i < freq.size() - k; i++) {
            total += freq[i];
        }

        return total;
    }
};