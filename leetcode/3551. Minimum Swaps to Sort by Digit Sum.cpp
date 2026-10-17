class Solution {
    using p = array<int, 2>;
public:
    int digSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // {num, index}
        vector<p> arrPos(n);
        for (int i = 0; i < n; i++) {
            arrPos[i] = {nums[i], i};
        }

        sort(arrPos.begin(), arrPos.end(), [this](const p& a, const p& b) {
            int sumA = digSum(a[0]), sumB = digSum(b[0]);
            if (sumA != sumB) return sumA < sumB;
            return a[0] < b[0];
        });

        int swaps = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || arrPos[i][1] == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j][1];
                cycleSize++;
            }
            
            if (cycleSize > 0) swaps += (cycleSize - 1);
        }

        return swaps;
    }
};