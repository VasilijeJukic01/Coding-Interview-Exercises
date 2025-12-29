class Solution {
public:
    // {value, origin}
    using p = array<int, 2>;

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<p, vector<p>, greater<>> pq;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                pq.push({nums[i][j], i});
            }
        }

        vector<p> sorted;
        while (!pq.empty()) {
            sorted.push_back(pq.top());
            pq.pop();
        }

        unordered_map<int, int> lookup;
        int counter = 0;
        int best = INT_MAX;
        vector<int> interval;

        int left = 0;
        for (int right = 0; right < sorted.size(); right++) {
            lookup[sorted[right][1]]++;
            if (lookup[sorted[right][1]] == 1) {
                counter++;
            }

            // Compress
            while (counter == k) {
                int range = sorted[right][0] - sorted[left][0];
                
                if (range < best) {
                    best = range;
                    interval = {sorted[left][0], sorted[right][0]};
                }

                lookup[sorted[left][1]]--;
                if (lookup[sorted[left][1]] == 0) {
                    counter--;
                }
                left++;
            }
        }

        return interval;
    }
};