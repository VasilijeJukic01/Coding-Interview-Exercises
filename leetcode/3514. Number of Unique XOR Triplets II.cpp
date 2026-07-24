class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());

        vector<int> u(unique.begin(), unique.end());
        unordered_set<int> pairs;
        for (int i = 0; i < u.size(); i++) {
            for (int j = i; j < u.size(); j++) {
                int x = u[i] ^ u[j];
                pairs.insert(x);
            }
        }

        unordered_set<int> triples;
        for (auto& x : unique) {
            for (auto& y : pairs) {
                int z = x ^ y;
                triples.insert(z);
            }
        }

        return triples.size();
    }
};