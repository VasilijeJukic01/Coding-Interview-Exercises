class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ranks(score.size(), "");
        int counter = 1;

        priority_queue<int> pq;
        unordered_map<int, int> map;
        
        for (int i = 0; i < score.size(); i++) {
            pq.push(score[i]);
            map[score[i]] = i;
        }

        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();

            if (counter == 1) ranks[map[x]] = "Gold Medal";
            else if (counter == 2) ranks[map[x]] = "Silver Medal";
            else if (counter == 3) ranks[map[x]] = "Bronze Medal";
            else ranks[map[x]] = to_string(counter);

            counter++;
        }

        return ranks;
    }
};