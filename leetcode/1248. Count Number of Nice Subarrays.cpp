class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int total = 0;

        int left = 0;
        queue<int> history;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] & 1) history.push(right);
            while (history.size() > k) {
                if (nums[left] & 1) history.pop();
                left++;
            }
            if (history.size() == k) {
                total += history.front() - left + 1;
            }
        }

        return total;
    }
};