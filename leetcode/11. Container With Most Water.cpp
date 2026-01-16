class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        int left = 0, right = height.size() - 1;
        while (left <= right) {
            int b = min(height[left], height[right]);
            int a = right - left;
            maxWater = max(maxWater, a * b);

            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxWater;
    }
};