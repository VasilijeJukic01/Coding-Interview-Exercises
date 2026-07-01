class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }

        int total = 0;
        while (!pq.empty()) {
            if (pq.size() == 1) break;

            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x == y) {
                total++;
                pq.push(x);
                if (x > 1) pq.push(x - 1);
            }
            else pq.push(y);
        }

        return total;
    }
};