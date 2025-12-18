class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }

            dq.push_back(nums[i]);

            if (i >= k) {
                int x = nums[i - k];
                if (dq.front() == x) dq.pop_front();
            }

            if (i >= k - 1) result.push_back(dq.front());
        }

        return result;
    }
};