class Solution {
public:
    int maxProduct(int n) {
        vector<int> map(10, 0);
        while (n) {
            int dig = n % 10;
            map[dig]++;
            n /= 10;
        }

        int max1 = 0, max2 = 0;
        for (int i = 9; i >= 0; i--) {
            while (map[i]) {
                if (max1 == 0) max1 = i;
                else max2 = i;
                map[i]--;
                if (max1 && max2) {
                    return max1 * max2;
                }
            }
        }

        return max1 * max2;
    }
};