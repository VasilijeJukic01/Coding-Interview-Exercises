class Solution {
public:
    bool formsTriangle(int a, int b, int c) {
        return a + b > c;
    }

    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());

        int total = 0;
        for (int k = nums.size() - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;
            while (left < right) {
                if (formsTriangle(nums[left], nums[right], nums[k])) {
                    total += (right - left);
                    right--;
                }
                else left++;
            }
        }

        return total;
    }
};