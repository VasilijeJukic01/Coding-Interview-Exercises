class Solution {
public:
    vector<bool> map;

    void solve(int n, int& counter, int used) {
        if (used == n) {
            counter++;
            return;
        }
        else if (used < n) counter++;

        for (int i = 0; i < 10; i++) {
            if (map[i] || (used == 0 && i == 0)) continue;
            map[i] = true;
            solve(n, counter, used + 1);
            // Backtrack
            map[i] = false;
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        map.resize(10, false);
        
        int counter = 0;
        solve(n, counter, 0);
        return counter;
    }
};