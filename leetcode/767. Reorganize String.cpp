class Solution {
public:
    // {chLeft, ch}
    using p = pair<int, char>;

    string reorganizeString(string s) {
        vector<int> map(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a']++;
        }

        priority_queue<p> pq;
        queue<p> q;

        for (int i = 0; i < 26; i++) {
            if (map[i] == 0) continue;
            pq.push({map[i], i + 'a'});
        }

        string result(s.size(), ' ');
        int index = 0;
        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();

            if (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }

            if (freq > 1) {
                q.push({freq - 1, ch});
            }

            result[index++] = ch;
        }

        if (pq.empty() && !q.empty()) return "";
        return result;
    }
};