class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0;
        long long maxReach = 0;
        
        int patches = 0;
        while (index < nums.size() && maxReach < n) {
            while (maxReach < n && nums[index] > maxReach + 1) {
                patches++;
                maxReach += maxReach + 1;
            }
            maxReach += nums[index++];
        }

        while (maxReach < n) {
            patches++;
            maxReach += maxReach + 1;
        }

        return patches;
    }
};