class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxFq = 0;
        int currFq = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) currFq++;
            else {
                maxFq = max(maxFq, currFq);
                currFq = 0;
            }
        }

        return max(maxFq, currFq);
    }
};