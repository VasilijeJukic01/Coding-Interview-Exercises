class Solution {
    using ll = long long;
public:
    ll minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> count(100001, 0);
        for (int i = 0; i < n; i++) {
            count[abs(nums1[i] - nums2[i])]++;
        }

        ll k = (ll)k1 + k2;
        for (int d = 100000; d > 0; d--) {
            if (count[d] == 0) continue;

            int push = min((ll)count[d], k);
            count[d] -= push;
            count[d - 1] += push;
            k -= push;

            if (count[d] > 0) break;
        }

        ll total = 0;
        for (int d = 1; d <= 100000; d++) {
            total += (ll)d * d * count[d];
        }

        return total;
    }
};