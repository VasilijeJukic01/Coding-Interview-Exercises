class Solution {
public:
    using p = pair<int, int>;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;

        for (auto const& [val, freq] : map) {
            pq.push({freq, val});
            if (pq.size() > k) pq.pop();
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};