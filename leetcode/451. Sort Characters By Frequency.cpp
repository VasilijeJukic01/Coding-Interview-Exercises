class Solution {
public:
    string frequencySort(string s) {
        // {frequency, code}
        vector<array<int, 2>> map(128, {0, 0});
        
        for (int i = 0; i < s.size(); i++) {
            map[s[i]] = {map[s[i]][0] + 1, s[i]};
        }

        sort(map.begin(), map.end(), [](auto& x, auto& y) {
            return x[0] > y[0];
        });

        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (map[index][0] == 0) index++;
            s[i] = map[index][1]; 
            map[index][0]--;
        }

        return s;
    }
};