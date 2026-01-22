class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> map(128, 0);
        vector<int> track(128, 0);

        for (int i = 0; i < t.size(); i++) {
            map[t[i]]++;
        }

        int need = 0;
        for (int i = 0; i < 128; i++) {
            if (map[i] != 0) need += map[i];
        }

        int left = 0;
        int counter = 0, best = INT_MAX;
        int start = -1;
        for (int right = 0; right < s.size(); right++) {
            track[s[right]]++;
            if (map[s[right]] != 0 && (track[s[right]] <= map[s[right]])) {
                counter++;
            }

            while (counter == need) {
                if ((right - left + 1) < best) {
                    best = right - left + 1;
                    start = left;
                }

                track[s[left]]--;
                if (map[s[left]] != 0 && (track[s[left]] < map[s[left]])) {
                    counter--;
                }
                left++;
            }
        }

        if (best == INT_MAX) return "";
        return s.substr(start, best);
    }
};