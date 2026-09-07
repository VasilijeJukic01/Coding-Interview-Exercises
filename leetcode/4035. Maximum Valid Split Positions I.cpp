class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n), right(n);

        int best = 0;
        for (int k = 0; k <= n; k++) {
            vector<int> a;
            for (int i = 0; i < n; i++) {
                if (k == i) continue;
                a.push_back(nums[i]);
            }

            if (a.size() == 1) continue;

            int m = a.size();
            left[0] = a[0];
            for (int i = 1; i < m; i++) {
                left[i] = gcd(left[i - 1], a[i]);
            }

            right[m - 1] = a[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                right[i] = gcd(right[i + 1], a[i]);
            }

            int score = 0;
            for (int i = 0; i < m - 1; i++) {
                if (left[i] == right[i + 1]) score++;
            }

            best = max(best, score);
        }
        
        return best;
    }
};