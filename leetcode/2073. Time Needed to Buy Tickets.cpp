class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int , bool>> q;

        for (int i = 0; i < tickets.size(); i++) {
            if (i == k) q.push({tickets[i], true});
            else q.push({tickets[i], false});
        }

        int time = 0;

        while (!q.empty()) {
            pair<int, bool> item = q.front();
            q.pop();
            time++;

            if (item.first - 1 > 0) {
                q.push({item.first - 1, item.second});
            }
            else if (item.second == true && item.first == 1) return time;
        }

        return time;
    }
};