class Solution {
public:
    int calculateDistance(vector<vector<int>>& f, int startPos, int left, int right) {
        if (startPos >= f[right][0]) return startPos - f[left][0];
        if (startPos <= f[left][0]) return f[right][0] - startPos;
        return min(startPos - f[left][0], f[right][0] - startPos) + f[right][0] - f[left][0];
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxFruits = 0;

        int collected = 0;
        int left = 0;
        for (int right = 0; right < fruits.size(); right++) {
            collected += fruits[right][1];

            int d = calculateDistance(fruits, startPos, left, right);
            while (left < right && d > k) {
                collected -= fruits[left][1];
                left++;
                d = calculateDistance(fruits, startPos, left, right);
            }

            if (d <= k) maxFruits = max(maxFruits, collected);
        }

        return maxFruits;
    }
};