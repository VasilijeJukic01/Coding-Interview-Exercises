class Solution {
public:
    int minOperations(vector<int>& nums) {
        int total = 0;
        stack<int> s;

        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[i] < s.top()) {
                s.pop();
            }
            if (nums[i] == 0) continue;
            if (s.empty() || nums[i] > s.top()) {
                total++;
                s.push(nums[i]);
            }
        }

        return total;
    }
};