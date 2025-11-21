class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        unordered_map<int, bool> map;

        for (int i = 0; i < friends.size(); i++) {
            map[friends[i]] = true;
        }

        for (int i = 0; i < order.size(); i++) {
            if (map[order[i]] == true) {
                result.push_back(order[i]);
            }
        }

        return result;
    }
};