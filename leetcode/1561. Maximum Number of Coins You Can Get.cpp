class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int steps = n / 3;
        int total = 0;
        for (int i = 0, j = n - 1; i < steps; i++, j -= 2) {
            total += piles[j - 1];
        }

        return total;
    }
};