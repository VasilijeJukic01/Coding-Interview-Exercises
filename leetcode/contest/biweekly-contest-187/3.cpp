class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
public:
    ll merge(vector<int>& a, int start, int end, int mid) {
        vector<int> t;
        int i = start, j = mid + 1;
        
        ll counter = 0;
        while (i <= mid && j <= end) {
            if (a[i] <= a[j]) t.push_back(a[i++]);
            else {
                t.push_back(a[j++]);
                counter = (counter + (mid - i + 1)) % MOD;
            }
        }

        while (i <= mid) {
            t.push_back(a[i++]);
        }
        while (j <= end) {
            t.push_back(a[j++]);
        }

        int p = 0;
        for (int k = start; k <= end; k++) {
            a[k] = t[p++];
        }

        return counter;
    }
    
    ll dnc(vector<int>& a, int start, int end) {
        if (start >= end) return 0;

        int mid = start + (end - start) / 2;
        ll count = 0;

        count = (count + dnc(a, start, mid)) % MOD;
        count = (count + dnc(a, mid + 1, end)) % MOD;
        count = (count + merge(a, start, end, mid)) % MOD;

        return count;
    }
    
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> categories(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] < a) categories[i] = 0;
            else if (nums[i] >= a && nums[i] <= b) {
                categories[i] = 1;
            }
            else categories[i] = 2;
        }

        return dnc(categories, 0, n - 1);
    }
};