class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n) {
            int maxima = -1;
            for (int i = 0; i < n; i++) {
                maxima = max(maxima, nums[i]);
            }
            return maxima;
        }

        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        vector<int> candidates;
        for (int i = 0; i < n; i++) {
            if (map[nums[i]] == 1) {
                candidates.push_back(nums[i]);
            }
        }

        if (candidates.empty()) return -1;

        if (k == 1) {
            int maxima = -1;
            for (int i = 0; i < candidates.size(); i++) {
                maxima = max(maxima, candidates[i]);
            }

            return maxima;
        }
        else {
            int cand1 = nums[0];
            int cand2 = nums[n - 1];

            int maxima = -1;
            for (int i = 0; i < candidates.size(); i++) {
                if (cand1 == candidates[i]) {
                    maxima = max(maxima, cand1);
                }
                else if (cand2 == candidates[i]) {
                    maxima = max(maxima, cand2);
                }
            }

            return maxima;
        }
    }
};