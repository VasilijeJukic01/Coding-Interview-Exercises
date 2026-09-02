class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minima = INT_MAX, maxima = INT_MIN;
        int minIdx = -1, maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minima) {
                minima = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxima) {
                maxima = nums[i];
                maxIdx = i;
            }
        }

        int option1 = max(minIdx, maxIdx) + 1;
        int option2 = n - min(minIdx, maxIdx);
        int option3 = (min(minIdx, maxIdx) + 1) + (n - max(minIdx, maxIdx));

        return min(min(option1, option2), option3);
    }
};