class Solution {
public:
    int conquer(vector<int>& pSum, int s, int e, int mid, vector<int>& tmp) {
        int total = 0;

        int left = s, right = mid + 1;
        while (left <= mid && right <= e) {
            if (pSum[right] > pSum[left]) {
                total += (e - right + 1);
                left++;
            }
            else right++;
        }

        left = s, right = mid + 1;
        int write = s;
        while (left <= mid && right <= e) {
            if (pSum[left] < pSum[right]) tmp[write++] = pSum[left++];
            else tmp[write++] = pSum[right++];
        }
        while (left <= mid) {
            tmp[write++] = pSum[left++];
        }
        while (right <= e) {
            tmp[write++] = pSum[right++];
        }

        for (int i = s; i <= e; i++) {
            pSum[i] = tmp[i];
        }

        return total;
    }

    int solve(vector<int>& pSum, int s, int e, vector<int>& tmp) {
        if (s >= e) return 0;

        int mid = s + (e - s) / 2;
        int count = solve(pSum, s, mid, tmp) + solve(pSum, mid + 1, e, tmp);
        count += conquer(pSum, s, e, mid, tmp);

        return count;
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }
        
        vector<int> pSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pSum[i + 1] = pSum[i] + nums[i];
        }

        vector<int> tmp(n + 1);
        return solve(pSum, 0, n, tmp);
    }
};