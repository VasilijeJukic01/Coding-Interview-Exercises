class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;

        int totalFlips = 0;
        int currFlips = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i == q.front()) {
                q.pop();
                currFlips--;
            }
            if ((nums[i] + currFlips) % 2 == 0) {
                if (i + k > nums.size()) return -1;
                totalFlips++;
                currFlips++;
                q.push(i + k);
            }
        }

        return totalFlips;
    }
};