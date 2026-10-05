class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> locations;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') locations.insert(i);
        }

        vector<int> result(boxes.size());
        for (int i = 0; i < boxes.size(); i++) {
            int moves = 0;
            for (auto& j : locations) {
                moves += abs(i - j);
            }
            result[i] = moves;
        }

        return result;
    }
};