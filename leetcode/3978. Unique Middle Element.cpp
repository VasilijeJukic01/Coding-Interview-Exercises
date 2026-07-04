class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size() / 2;
        int x = nums[mid];

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) cnt++;
        }

        return cnt == 1;
    }
};