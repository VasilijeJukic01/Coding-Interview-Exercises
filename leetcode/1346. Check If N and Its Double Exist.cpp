class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        for (auto item : map) {
            // The number is 0
            if (item.first == 0) {
                if (item.second > 1) return true;
            }
            // The number is not 0
            else {
                if (map.find(2 * item.first) != map.end()) return true;
            }
        }

        return false;
    }
};