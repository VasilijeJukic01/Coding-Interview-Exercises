class Solution {
public:
    int count(int x) {
        if (x >= 0 && x <= 9) return 0;

        int total = 0;
        string num = to_string(x);
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i] > num[i - 1] && num[i] > num[i + 1]) {
                total++;
            }
            if (num[i] < num[i - 1] && num[i] < num[i + 1]) {
                total++;
            }
        }

        return total;
    }

    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += count(i);
        }

        return total;
    }
};