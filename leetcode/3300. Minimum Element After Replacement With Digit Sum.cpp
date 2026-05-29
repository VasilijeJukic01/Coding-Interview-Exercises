class Solution {
public:
    int minElement(vector<int>& nums) {
        int minima = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            int n = nums[i];
            while (n) {
                sum += (n % 10);
                n /= 10;
            }

            minima = min(minima, sum);
        }

        return minima;
    }
};