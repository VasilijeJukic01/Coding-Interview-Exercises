class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int maxNum = INT_MIN;
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                index = i;
            }
        }

        stack<int> s;
        vector<int> result(n, -1);
        s.push(nums[index]);

        int currIndex = (index - 1 + n) % n;
        for (int i = 1; i < n; i++) {
            while (!s.empty() && nums[currIndex] >= s.top()) {
                s.pop();
            }
            if (!s.empty()) result[currIndex] = s.top();
            s.push(nums[currIndex]);
            currIndex = (currIndex - 1 + n) % n;
        }

        return result;

    }
};