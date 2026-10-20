class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> divisors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) divisors.push_back(i);
        }

        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        int sum = 0;
        for (auto& k : divisors) {
            bool valid = true;

            for (int start = 0; start < n; start += k) {
                int drops = 0;
                int dropIndex = 0;
                for (int j = 0; j < k - 1; j++) {
                    if (nums[start + j] > nums[start + j + 1]) {
                        drops++;
                        dropIndex = start + j + 1;
                    }
                }

                if (drops > 1) {
                    valid = false;
                    break;
                }

                for (int j = 0; j < k; j++) {
                    int offset = (dropIndex + j) % k;
                    int idx = start + offset;
                    if (nums[idx] != sorted[start + j]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (valid) sum += k;
        }

        return sum;
    }
};