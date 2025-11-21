class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> map(10, 0);

        while (n) {
            map[n % 10]++;
            n /= 10;
        }

        int minFq = INT_MAX;
        int number = 0;
        for (int i = 0; i < 10; i++) {
            if (map[i] != 0 && map[i] < minFq) {
                minFq = map[i];
                number = i;
            }
        }

        return number;
    }
};