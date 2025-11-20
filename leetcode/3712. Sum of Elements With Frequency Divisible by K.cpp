class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> map(101, 0);
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (int i = 1; i < map.size(); i++) {
            if (map[i] % k == 0) sum += i * map[i];
        }

        return sum;
    }
};