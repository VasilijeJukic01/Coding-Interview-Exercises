class Solution {
public:
    // bucket item -> {min, max}
    using p = array<int, 2>;

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int leftBound = INT_MAX;
        int rightBound = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            leftBound = min(leftBound, nums[i]);
            rightBound = max(rightBound, nums[i]);
        }

        int avgGap = (rightBound - leftBound) / (n - 1);
        int bucketSize = max(1, avgGap);
        int bucketCount = (rightBound - leftBound) / bucketSize + 1;
        vector<p> buckets(bucketCount, {INT_MAX, INT_MIN});

        for (int i = 0; i < nums.size(); i++) {
            int id = (nums[i] - leftBound) / bucketSize;
            buckets[id][0] = min(buckets[id][0], nums[i]);
            buckets[id][1] = max(buckets[id][1], nums[i]);
        }

        int maxGap = 0;
        int prevMax = leftBound;
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i][0] == INT_MAX) continue;
            maxGap = max(maxGap, buckets[i][0] - prevMax);
            prevMax = buckets[i][1];
        }

        return maxGap;
    }
};