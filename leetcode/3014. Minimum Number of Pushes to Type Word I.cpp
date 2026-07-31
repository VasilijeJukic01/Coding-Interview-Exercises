class Solution {
public:
    int minimumPushes(string word) {
        vector<int> map(26, 0);

        for (int i = 0; i < word.size(); i++) {
            map[word[i] - 'a']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (map[i]) pq.push(map[i]);
        }

        int total = 0;
        int counter = 0, k = 1;
        while (!pq.empty()) {
            pq.pop();
            total += k;
            counter++;
            if (counter == 8) {
                counter = 0;
                k++;
            }
        }

        return total;
    }
};