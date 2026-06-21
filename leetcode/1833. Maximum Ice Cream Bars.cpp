class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int allocation = 0;
        for (int i = 0; i < costs.size(); i++) {
            allocation = max(allocation, costs[i]);
        }

        vector<int> map(allocation + 1, 0);

        for (int i = 0; i < costs.size(); i++) {
            map[costs[i]]++;
        }

        int total = 0;
        for (int i = 0; i < map.size(); i++) {
            long long key = i, val = map[i];
            if (!map[i]) continue;

            if ((long long)(key * val) <= coins) {
                total += val;
                coins -= (long long)(key * val);
            }
            else if (coins >= key) {
                total += coins / key;
                break;
            }
            else break;
        }

        return total;
    }
};