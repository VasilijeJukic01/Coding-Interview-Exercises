class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int total = 2 * n;

        // {row, seats}
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < reservedSeats.size(); i++) {
            map[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }

        for (auto& [row, seats] : map) {
            bool left = false, middle = false, right = false;
            for (int i = 2; i <= 9; i++) {
                if (!seats.count(i)) continue;

                if (i >= 2 && i <= 5) left = true;
                if (i >= 4 && i <= 7) middle = true;
                if (i >= 6 && i <= 9) right = true;
            }
            
            // All zones blocked
            if (left && right && middle) total -= 2;
            // One zone blocked
            else if (left || right) total -= 1;
        }

        return total;
    }
};